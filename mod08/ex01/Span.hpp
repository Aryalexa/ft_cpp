
#pragma once


#include <vector>
#include <iostream>


class Span
{
private:
	unsigned int N;
	std::vector<int> nums;

	Span();
public:
	Span(unsigned int N);
	

	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template <class InputIterator>
	void addNumbers(InputIterator first, InputIterator last);

	void display();
};

template <typename InputIterator>
void Span::addNumbers(InputIterator first, InputIterator last) {
	std::vector<int> tmp(first, last);
	if (nums.size() + tmp.size() >= N)
		throw std::runtime_error("too many numbers");
		
	nums.insert(nums.end(), first, last);
}