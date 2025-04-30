
#include <iostream>
#include <string>
#include <sstream>
#include <list>

static std::list<int> get_args_as_ints(int argn, char *argv[]) {
	std::list<int> nums;
	std::ostringstream oss;
	for (int i = 1; i < argn; ++i) {
		std::istringstream iss(argv[i]);
		int num;
		iss >> num;
		if (!iss || !iss.eof()) {
			oss << "non integer encountered" <<
				" - arg #" << i << ": " << argv[i];
			throw std::runtime_error(oss.str());
		}
		if (num < 0) {
			oss << "not positive integer encountered" <<
				" - arg #" << i << ": " << argv[i];
			throw std::runtime_error(oss.str());	
		}
		nums.push_back(num);
	}
	return nums;
}

static void print_numlist(const std::list<int> &nums) {
	std::list<int>::const_iterator it;
	for (it = nums.begin(); it!=nums.end(); ++it) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}

int main(int argn, char *argv[]) {

	try {
		std::list<int> nums = get_args_as_ints(argn, argv);
		print_numlist(nums);
		//c1

		//c2

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
	
}