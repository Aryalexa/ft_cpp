#include "BitcoinExchange.hpp"

using std::string;

// class const members (static)
const string BitcoinExchange::DB_FILENAME = "data.csv";
const string BitcoinExchange::DB_HEADER = "date,exchange_rate";
const string BitcoinExchange::WALLET_HEADER = "date | value";
const double BitcoinExchange::MIN_VAL = 0;
const double BitcoinExchange::MAX_VAL = 1000;

// class members (static)
BitcoinExchange::map_date_price BitcoinExchange::price_hist;
BitcoinExchange::dateStr BitcoinExchange::max_data_date;
BitcoinExchange::dateStr BitcoinExchange::min_data_date;


static void read_header(string actual_header, string expected_header) {
	if (actual_header != expected_header)
		throw std::runtime_error("header: bad format");
}

void BitcoinExchange::read_price_line(const string& line) {		
	dateStr date = "";
	double val;
	char sep = ',';

	// check format
	std::istringstream iss(line);
	std::getline(iss, date, sep);
	iss >> val;
	if (!iss || date.empty() || !iss.eof()) {
		throw std::runtime_error("bad format");
	}
	BitcoinExchange::price_hist[date] = val;
}

void BitcoinExchange::load_price_hist() {
	string line;
	int line_num;
	
	// open DB file
	std::ifstream fin(DB_FILENAME, std::ios::in);
	if (!fin) 
		throw std::runtime_error("DB file not found!");
	// read DB header
	std::getline(fin, line);
	read_header(line, DB_HEADER);
	// for each line in DB:
	line_num = 2; // start at 1 + header line
	while (std::getline(fin, line)) {
		try {
			read_price_line(line);
		}
		catch (const std::exception& e) {
			std::ostringstream oss;
			oss << "DB file error. Line " << line_num << ": " << e.what();
			throw std::runtime_error(oss.str());
		}
		++line_num;		
	}
	fin.close();

	//print_map_date_price(BitcoinExchange::price_hist);

	// save min and max dates in DB
	map_date_price::iterator it;
	// save first
	it = price_hist.begin();
	BitcoinExchange::min_data_date = (*it).first;
	// save last
	it = price_hist.end();
	if (it != price_hist.begin()) --it;
	BitcoinExchange::max_data_date = (*it).first;
	std::cout << "BTC prices." << 
		" Data since " << min_data_date << 
		" until " << max_data_date << 
		std::endl;
}

void BitcoinExchange::print_map_date_price(const map_date_price& map, unsigned int max){
	map_date_price::const_iterator it;
	unsigned int i = 0;
	it = map.begin();
	std::cout << "BTC prices" << std::endl;
	std::cout << "date: price" << std::endl;

	while (it != map.end() && i < max)
	{
		std::cout << it->first << ": " << it->second << std::endl;
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

    std::tm t = {}; // zero-initialize
    t.tm_year = y - 1900; // since 1900
    t.tm_mon = m - 1; // 0-11
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
void BitcoinExchange::process_wallet_line(const string& line) {		
	std::ostringstream oss;
	dateStr date = "";
	double val;
	char pipe;

	// check format
	std::istringstream iss(line);
	iss >> date >> pipe >> val;
	if (!iss || date.empty() || pipe != '|') {
		throw std::runtime_error("bad format");
	}
	if (!iss.eof()) {
		throw std::runtime_error("bad format, extra input");	
	}
	// check valid date
	if (!is_valid_date(date)) {
		oss << "bad input => " << date << " (invalid date)";
		throw std::runtime_error(oss.str());
	}
	if (date < min_data_date) {
		oss << "bad input => " << date << " (date prior to data base)";
		throw std::runtime_error(oss.str());	
	}
	if (date > max_data_date) {
		oss << "bad input => " << date << " (date exceeds data base)";
		throw std::runtime_error(oss.str());	
	}
	// check valid values
	if (val < MIN_VAL) {
		oss << "bad input => " << val << " (value is negative)";
		throw std::runtime_error(oss.str());
	}
	if (val > MAX_VAL) {
		oss << "bad input => " << val << " (value not supported. Too large)";
		throw std::runtime_error(oss.str());
	}
	// all ok
	// get price for date (or closest prior date)
	// lower_bound returns the first element with key >= date
	map_date_price::iterator it = price_hist.lower_bound(date);
	if (it->first != date && it != price_hist.begin())
		--it;
	double price = it->second;
	
	oss << "⏩ " << date << 
		": " << std::setw(6) << val << " btc"  << 
		std::fixed << std::setprecision(2) <<
		" * "  << price << 
		" = " << price * val;
	std::cout << oss.str() << std::endl;
}

void BitcoinExchange::display_wallet_value(string wallet_filename) {
	string line;
	int line_num;
	
	// open
	std::ifstream fin(wallet_filename, std::ios::in);
	if (!fin) 
		throw std::runtime_error("wallet file not found!");
	// read wallet header
	std::getline(fin, line);
	read_header(line, WALLET_HEADER);
	// for each line in wallet:
	line_num = 2; // start at 1 + header line
	while (std::getline(fin, line)) {
		try {
			process_wallet_line(line);
		} catch (std::exception &e) {
			std::cout << "Error. Line " << line_num << ": "
				<< e.what() << std::endl;
		}
		++line_num;		
	}
	fin.close();
}
