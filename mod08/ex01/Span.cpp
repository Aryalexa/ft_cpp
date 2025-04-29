#include "Span.hpp"

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
	
	shortest = std::abs(nums[0] - nums[1]);
	for (unsigned int i = 0; i < nums.size(); ++i) 
		for (unsigned int j = i + 1; j < nums.size(); ++j) {
			unsigned int span = abs(nums[i] - nums[j]);
			if (span < shortest)
				shortest = span;
		}
	return shortest;
}
unsigned int Span::longestSpan() {
	unsigned int longest;

	if (nums.size() < 2)
		throw std::runtime_error("not enough numbers");
	
	longest = std::abs(nums[0] - nums[1]);
	for (unsigned int i = 0; i < nums.size(); ++i) 
		for (unsigned int j = i + 1; j < nums.size(); ++j) {
			unsigned int span = abs(nums[i] - nums[j]);
			if (span > longest)
				longest = span;
		}
	return longest;
}

void Span::display() {
	std::cout << "The contents of span are: ";
	std::vector<int>::iterator it;	
  	for (it = nums.begin(); it != nums.end(); it++)
    	std::cout << *it << ' ';
	std::cout << '\n';
}