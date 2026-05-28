
#include "BitcoinExchange.hpp"

int main(int argn, char *argv[]) {
	if (argn != 2) {
		std::cerr << "Error: Expected one wallet file." << std::endl;
		return (1);
	}
	try {
		BitcoinExchange::load_price_hist();
		BitcoinExchange::display_wallet_value(argv[1]);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}