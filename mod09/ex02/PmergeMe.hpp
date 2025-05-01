
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <map>
#include <algorithm>

/**
 * t_k = ( 2^(k+1) + (-1)^k ) / 3
 */
static unsigned int index_t(unsigned int k) {
	using std::pow;
	return ( pow(2, k + 1) + pow(-1, k)) / 3;
}

template <typename C>
void print_nums(const C &nums) {
	typename C::const_iterator it;
	for (it = nums.begin(); it!=nums.end(); ++it) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}

static size_t min(size_t n1, size_t n2) {
	if (n1 < n2)
		return n1;
	return n2;
}

class PmergeMe1
{
private:
	typedef std::vector<int> contType;
	
	PmergeMe1();
	PmergeMe1(const PmergeMe1 &other);
	PmergeMe1 &operator=(const PmergeMe1 &other);
	~PmergeMe1();
	
	static PmergeMe1::contType mergeinsert_sort(contType c);
	static PmergeMe1::contType binary_insertion(contType c, int elem, size_t limit);
	static int binarySearch(contType a, int elem, int low, int high);
	
public:
	static const std::string CONTAINER_NAME;
	static void sort(std::list<int> nums);

};

const std::string PmergeMe1::CONTAINER_NAME = "vector";

/**
 * returns position to insert
 */
int PmergeMe1::binarySearch(PmergeMe1::contType a, int elem, int low, int high)
{
    if (high <= low)
        return (elem > a[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;
    // if (elem == a[mid])
    //     return mid + 1;
    if (elem > a[mid])
        return binarySearch(a, elem, mid + 1, high);
    return binarySearch(a, elem, low, mid - 1);
}

PmergeMe1::contType PmergeMe1::binary_insertion(contType c, int elem, size_t limit) {
	size_t loc = binarySearch(c, elem, 0, limit);
	c.insert(c.begin() + loc, elem);
	return c;
}

PmergeMe1::contType PmergeMe1::mergeinsert_sort(contType d) {

	size_t n = d.size();
	if (n == 1) return d;
	// 1. pairwise comparison
	contType a;
	contType b;
	for (size_t i = 0; i < n/2; ++i) {
		if (d[i*2] < d[i*2 + 1]) {
			a.push_back(d[i*2]);
			b.push_back(d[i*2 + 1]);
		} else {
			a.push_back(d[i*2 + 1]);
			b.push_back(d[i*2]);	
		}
	}
	if (n % 2 == 1)
	b.push_back(d[n - 1]);	
	// 2. Recursion and renaming
	std::map<int, int> m;
	for (size_t i = 0; i < n/2; ++i) {
		m[a[i]] = b[i];
	}
	a = mergeinsert_sort(a);
	for (size_t i = 0; i < n/2; ++i) {
		b[i] = m[a[i]];
	}
	// 3. Insertion
	d = a;
	d.insert(d.begin(),b[0]);
	unsigned int k = 2;
	unsigned int upper_half_n = n/2 + n%2;
	while (index_t(k - 1) < upper_half_n) {
		// first element of the batch
		unsigned int ini = ::min(index_t(k), upper_half_n) - 1; //idx0
		// position of a[ini] in d
		int u = index_t(k - 1) + ini - 1; //idx0
		for (size_t i = ini; i > index_t(k - 1) + 1; --i) {
			d = binary_insertion(d, b[i], u);
			// adjust u
			while (d[u] != a[i])
				--u;
		}
		++k;
	}
	return d;
}

void PmergeMe1::sort(std::list<int> nums) {
	// fill cont
	contType c = contType(nums.begin(), nums.end());
	// sort
	c = mergeinsert_sort(c);
	print_nums(c);

}
