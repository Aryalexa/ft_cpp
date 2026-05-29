
#include <iostream>
#include <string>
#include <sstream>
#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>



static std::deque<int> get_args_as_ints(int argn, char *argv[]) {
	std::deque<int> nums;
	std::ostringstream oss;
	for (int i = 1; i < argn; ++i) {
		std::istringstream iss(argv[i]);
		int num;
		iss >> num;
		if (!iss || !iss.eof()) {
			oss << "Error: non integer argument";
			throw std::runtime_error(oss.str());
		}
		if (num < 0) {
			oss << "Error: not positive integer";
			throw std::runtime_error(oss.str());	
		}
		nums.push_back(num);
	}
	if (nums.empty())
		throw std::runtime_error("Error: no numbers provided");
	return nums;
}

template <typename Container>
void print_nums(const std::string &msg, const Container &nums) {
	std::cout << msg << " ";
	for (typename Container::const_iterator it = nums.begin(); it != nums.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main(int argn, char *argv[]) {

	try {
		std::deque<int> nums = get_args_as_ints(argn, argv);
		if (nums.size() < 1)
			return 0;
		print_nums("Before:", nums);

		std::clock_t start, end;
		//c1
		const std::string container1 = "std::deque<int>";
		std::deque<int> res1 = nums;
		start = std::clock();
		PmergeMe::sort(res1);
		end = std::clock();
		double time1 = double(end - start) / CLOCKS_PER_SEC * 1000.0;  // clock ticks to ms

		//c2
		const std::string container2 = "std::vector<int>";
		std::vector<int> res2(nums.begin(), nums.end());
		start = std::clock();
		PmergeMe::sort(res2);
		end = std::clock();
		double time2 = double(end - start) / CLOCKS_PER_SEC * 1000.0;  // clock ticks to ms

		print_nums("After:", res1);
		//print_nums("result", res2);
		/**
		 * Time to process a range of 5 elements with std::[..] : 0.00031 us
		 * Time to process a range of 5 elements with std::[..] : 0.00014 us
		 */
		std::cout << "Time to process a range of " << nums.size() << " elements with " <<
			std::setw(16) << 
			container1 << " : " << time1 << " ms" << std::endl;
		std::cout << "Time to process a range of " << nums.size() << " elements with " <<
			std::setw(16) << 
			container2 << " : " << time2 << " ms" << std::endl;

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
	
}