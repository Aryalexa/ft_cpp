
#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <list>
#include <map>
#include <vector>
#include <algorithm>


class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	static std::vector<size_t> jacobsthal_order(size_t n);
public:
	static void sort(std::vector<int> &v);
	static void sort(std::deque<int> &v);
};