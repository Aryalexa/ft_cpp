#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::PRICE_HIST_CSV = "data.csv";
const std::string BitcoinExchange::PRICE_HIST_HEADER = "date,exchange_rate";
const std::string BitcoinExchange::INPUT_HEADER = "date | value";
const double BitcoinExchange::MIN_VAL = 0;
const double BitcoinExchange::MAX_VAL = 1000;
BitcoinExchange::map_date_price BitcoinExchange::price_hist;
BitcoinExchange::dateStr BitcoinExchange::max_data_date;
BitcoinExchange::dateStr BitcoinExchange::min_data_date;



static void read_header(std::string actual_header, std::string expected_header) {
	if (actual_header != expected_header)
	{
		std::cout << "header read: [" << actual_header << "]" << std::endl;
		throw std::runtime_error("header: bad format");
	}
}

void BitcoinExchange::read_price_line(const std::string& line, int line_num) {		
	std::ostringstream oss;
	dateStr date = "";
	double val;
	char sep = ',';

	// check format
	std::istringstream iss(line);
	std::getline(iss, date, sep);
	iss >> val;
	if (!iss || date.empty() || !iss.eof()) {
		oss << "line " << line_num << ": bad format";
		throw std::runtime_error(oss.str());
	}
	BitcoinExchange::price_hist[date] = val;
}

void BitcoinExchange::load_price_hist() {
	if (BitcoinExchange::price_hist.size() > 0)
		return;
	
	using std::string;
	string line;
	int line_num;
	
	// open to read
	std::ifstream fin(PRICE_HIST_CSV, std::ios::in);
	if (!fin) 
		throw std::runtime_error("DB file not found!");
	// read input header
	std::getline(fin, line);
	read_header(line, PRICE_HIST_HEADER);
	// for each line in input
	line_num = 1;
	while (std::getline(fin, line)) {
		read_price_line(line, line_num);
		++line_num;		
	}
	fin.close();

	//print_map_date_price(BitcoinExchange::price_hist);

	// min and max dates in DB
	map_date_price::iterator it;

	it = price_hist.begin();
	BitcoinExchange::min_data_date = (*it).first;
	it = price_hist.end();
	--it;
	BitcoinExchange::max_data_date = (*it).first;
	std::cout << "BTC prices." << 
		" Data since " << min_data_date << 
		" until " << max_data_date << 
		std::endl << std::endl;
}

void BitcoinExchange::print_map_date_price(const map_date_price& map, unsigned int max){
	map_date_price::const_iterator it;
	unsigned int i = 0;
	it = map.begin();
	std::cout << "BTC prices" << std::endl;
	std::cout << "date: price" << std::endl;

	while (it != map.end() && i < max)
	{
		std::cout << (*it).first << ": " << (*it).second << std::endl;
		++it;
		++i;
	}
	std::cout << std::endl;
}

bool BitcoinExchange::is_valid_date(const dateStr& date_str) {
	int y, m, d;
    char dash1, dash2;

    std::istringstream iss(date_str);
    iss >> y >> dash1 >> m >> dash2 >> d;

    if (!iss || dash1 != '-' || dash2 != '-' || !iss.eof())
		return false;

    // Basic range validation
    if (y < 1900 || m < 1 || m > 12 || d < 1 || d > 31) 
		return false;

    std::tm t = {};
    t.tm_year = y - 1900;
    t.tm_mon = m - 1;
    t.tm_mday = d;

    // Normalize using mktime
    std::time_t time = std::mktime(&t);
    if (time == -1)
		return false;

    // Check if fields remain consistent (detects invalid dates like Feb 30)
    if (t.tm_year != y - 1900 || t.tm_mon != m - 1 || t.tm_mday != d)
		return false;

	// check no future dates
	std::time_t now = std::time(0); // current time
	if (time > now)
		return false;

    return true;
}

/**
 * parse and process:
 * - checks: format, valid dates, valid values
 * - join with price hist (date:price) to get the wallet evolution
 * - display wallet ev
 */
void BitcoinExchange::process_input_line(const std::string& line, int line_num) {		
	std::ostringstream oss;
	dateStr date = "";
	double val;
	char pipe;

	// check format
	std::istringstream iss(line);
	iss >> date >> pipe >> val;
	if (!iss || date.empty() || pipe != '|') {
		oss << "line " << line_num << ": bad format";
		throw std::runtime_error(oss.str());
	}
	if (!iss.eof()) {
		oss << "line " << line_num << ": bad format, extra input";
		throw std::runtime_error(oss.str());	
	}
	// check valid date
	if (!is_valid_date(date)) {
		oss << "line " << line_num << ": invalid date (" << date << ")";
		throw std::runtime_error(oss.str());
	}
	if (date < min_data_date) {
		oss << "line " << line_num << ": date prior to data base (" << date << ")";
		throw std::runtime_error(oss.str());	
	}
	if (date > max_data_date) {
		oss << "line " << line_num << ": date exceeds data base (" << date << ")";
		throw std::runtime_error(oss.str());	
	}
	// check valid values
	if (val < MIN_VAL) {
		oss << "line " << line_num << ": not a positive value (" << val << ")";
		throw std::runtime_error(oss.str());
	}
	if (val > MAX_VAL) {
		oss << "line " << line_num << ": value not supported";
		throw std::runtime_error(oss.str());
	}
	// all ok
	map_date_price::iterator it = price_hist.lower_bound(date);
	if (it->first != date)
		--it;
	double price = (*it).second;
	
	oss << "⏩ " << date << 
		": " << std::setw(6) << val << " btc"  << 
		std::fixed << std::setprecision(2) <<
		" * "  << price << 
		" = " << price * val;
	std::cout << oss.str() << std::endl;
}

void BitcoinExchange::display_wallet(std::string wallet_filename) {

	load_price_hist();

	using std::string;
	string line;
	int line_num;
	
	// open to read
	std::ifstream fin(wallet_filename, std::ios::in);
	if (!fin) 
		throw std::runtime_error("input file not found!");
	// read input header
	std::getline(fin, line);
	read_header(line, INPUT_HEADER);
	// for each line in input
	line_num = 1;
	while (std::getline(fin, line)) {
		try {
			process_input_line(line, line_num);
		} catch (std::exception &e) {
			std::cout << "Error. " << e.what() << std::endl;
		}
		++line_num;		
	}
	fin.close();
}
