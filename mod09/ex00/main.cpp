
#include "BitcoinExchange.hpp"

int main(int argn, char *argv[]) {
	if (argn != 2) {
		std::cout << "give me one file" << std::endl;
		return (0);
	}
	BitcoinExchange::display_wallet(argv[1]);
	return (0);
}