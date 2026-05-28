
#include "RPN.hpp"
#include <iostream>
#include <iomanip>

int main(int argn, char *argv[]) {

	if (argn != 2) {
		std::cerr << "Error. Expected one argument: a polish notation expression in a string" << std::endl;
		return 1;
	}
	try {
		double res = RPN::solve(argv[1]);
		std::cout << std::fixed << std::setprecision(0) << res << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
