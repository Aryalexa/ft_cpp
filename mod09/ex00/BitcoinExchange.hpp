#pragma once

#include <map>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


class BitcoinExchange
{
private:
	typedef std::string dateStr;
	typedef std::map<dateStr, double> map_date_price;

	static const std::string DB_FILENAME;
	static const std::string DB_HEADER;
	static const std::string WALLET_HEADER;
	static const double MIN_VAL;
	static const double MAX_VAL;

	static map_date_price price_hist;
	static dateStr max_data_date;
	static dateStr min_data_date;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	

	static void read_price_line(const std::string& line);
	static bool is_valid_date(const dateStr &date_str);
	static void process_wallet_line(const std::string& line);
	static void print_map_date_price(const map_date_price& map, unsigned int max=10);
	
public:
	static void load_price_hist();
	static void display_wallet_value(std::string wallet_filename);

};
