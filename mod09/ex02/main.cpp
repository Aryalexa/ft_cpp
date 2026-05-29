
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>



bool  in_set(std::set<int> s, int elem) {
	std::set<int>::iterator it = s.find(elem);
	if (it != s.end())
		return true;
	return false;
}

static std::deque<int> get_args_as_ints(int argn, char *argv[]) {
	std::deque<int> nums;
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

void print_nums(const std::string &msg, const std::vector<int> &nums) {
	std::cout << msg << " ";
	for (size_t i = 0; i < nums.size(); ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
}
void print_nums(const std::string &msg, const std::deque<int> &nums) {
	std::cout << msg << " ";
	for (std::deque<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
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

		timeval start, end;

		//c1
		const std::string container1 = "std::deque<int>";
		std::deque<int> res1 = nums;
		gettimeofday(&start, NULL);
		PmergeMe::sort(res1);
		gettimeofday(&end, NULL);
		double time1 = (end.tv_sec - start.tv_sec) * 1000.0;      // sec to ms
		time1 += (end.tv_usec - start.tv_usec) / 1000.0;          // us to ms

		//c2
		const std::string container2 = "std::vector<int>";
		std::vector<int> res2 = nums.size() > 0 ? std::vector<int>(nums.begin(), nums.end()) : std::vector<int>();
		gettimeofday(&start, NULL);
		PmergeMe::sort(res2);
		gettimeofday(&end, NULL);
		double time2 = (end.tv_sec - start.tv_sec) * 1000.0;      // sec to ms
		time2 += (end.tv_usec - start.tv_usec) / 1000.0;          // us to ms

		// assert_same(res1, res2);
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