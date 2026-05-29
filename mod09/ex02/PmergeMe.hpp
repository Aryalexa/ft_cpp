
#pragma once

#include <vector>
#include <deque>


class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	static std::vector<size_t> j_seq;
	static size_t j_(size_t n);

	static std::vector<size_t> jacobsthal_order(size_t n);
public:
	static void sort(std::vector<int> &v);
	static void sort(std::deque<int> &v);
};