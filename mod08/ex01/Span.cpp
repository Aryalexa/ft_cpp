#include "Span.hpp"
#include <cstdlib> // for std::abs
#include <ctime>

Span::Span() {}

Span::Span(unsigned int N): N(N) {}
Span::Span(const Span &other): N(other.N), nums(other.nums) {}
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		nums = other.nums;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (nums.size() < N)
		nums.push_back(num);
	else
		throw std::runtime_error("max already reached");
}
unsigned int Span::shortestSpan() {
	unsigned int shortest;

	if (nums.size() < 2)
		throw std::runtime_error("not enough numbers");
	
	// Create a copy and sort it for efficient span calculation
	std::vector<int> sorted_nums(nums.begin(), nums.end());
	std::sort(sorted_nums.begin(), sorted_nums.end());
	
	// The shortest span is always between adjacent elements in sorted array
	shortest = sorted_nums[1] - sorted_nums[0];
	for (unsigned int i = 1; i < sorted_nums.size(); ++i) {
		unsigned int span = sorted_nums[i] - sorted_nums[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}
unsigned int Span::longestSpan() {
	unsigned int longest;

	if (nums.size() < 2)
		throw std::runtime_error("not enough numbers");
	
	// The longest span is simply max - min
	std::vector<int> sorted_nums(nums.begin(), nums.end());
	std::sort(sorted_nums.begin(), sorted_nums.end());
	
	longest = sorted_nums[sorted_nums.size() - 1] - sorted_nums[0];
	return longest;
}

void Span::display() {
	std::cout << "The contents of span are: ";
	std::vector<int>::iterator it;	
  	for (it = nums.begin(); it != nums.end(); it++)
    	std::cout << *it << ' ';
	std::cout << '\n';
}