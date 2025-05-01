
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <set>
#include "PmergeMe.hpp"


bool  in_set(std::set<int> s, int elem) {
	std::set<int>::iterator it = s.find(elem);
	if (it != s.end())
		return true;
	return false;
}

static std::list<int> get_args_as_ints(int argn, char *argv[]) {
	std::list<int> nums;
	std::set<int> numset;
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
		if (in_set(numset, num))
			continue;
		numset.insert(num);
		nums.push_back(num);
	}
	return nums;
}



int main(int argn, char *argv[]) {

	try {
		std::list<int> nums = get_args_as_ints(argn, argv);
		if (nums.size() < 1)
			return 0;
		print_nums("input", nums);

		//c1
		PmergeMe1::sort(nums);
		//c2

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
	
}