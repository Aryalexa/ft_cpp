
#include "RPN.hpp"
#include <iostream>
#include <iomanip>

#define MAX_NUMS = 10;
int main(int argn, char *argv[1]) {

	if (argn != 2) {
		std::cout << "give me one argument" << std::endl;
		return 0;
	}
	try {
		double res = RPN::solve(argv[1]);
		std::cout << std::fixed << std::setprecision(0) << res << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
