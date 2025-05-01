
#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

size_t min(size_t n1, size_t n2);
unsigned int index_t(unsigned int k);

// ------------------------------------------------

template <typename C>
void print_nums(const std::string &msg, const C &nums) {
	std::cout << msg << "\t";
	typename C::const_iterator it1;
	for (it1 = nums.begin(); it1!=nums.end(); ++it1) {
		std::cout << (*it1) << " ";
	}
	std::cout << std::endl;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& set)
{
    if (set.empty())
        return out << "[]";

    typename std::vector<T>::const_iterator it = set.begin();
    out << "[ " << *it;
    ++it;
    for (; it != set.end(); ++it)
    {
        out << ", " << *it;
    }
    return out << " ]";
}

template <typename C1, typename C2>
void assert_same(const C1 &c1, const C2 &c2) {
	if (c1.size() != c2.size())
		throw std::runtime_error("size is not the same!");
	typename C1::const_iterator it1 = c1.begin();
	typename C2::const_iterator it2 = c2.begin();
	while (it1 != c1.end() && it2 != c2.end()) {
		if ( *it1 != *it2)
			throw std::runtime_error("contain is not the same");
		++it1;
		++it2;
	}
}

// ------------------------------------------------

template <typename contType>
class PmergeMe
{
private:
	//typedef std::vector<int> contType;
	
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	
	static void mergeinsert_sort(contType &c);
	static void binary_insertion(contType &c, int elem, size_t limit);
	static int binarySearch(const contType &a, int elem, int low, int high);
	
public:
	static contType sort(std::list<int> nums);

};

// ------------------------------------------------

/**
 * returns position to insert
 * - low and high are both included in the search.
 */
template <typename contType>
int PmergeMe<contType>::binarySearch(const contType &a, int elem, int low, int high)
{
	// std::cout << "   binSearch " << elem 
	// 	<< " in " << a << " [" << low << "," << high << "]" << std::endl;
    if (high <= low)
        return (elem > a[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;
    // if (elem == a[mid])
    //     return mid + 1;
    if (elem > a[mid])
        return binarySearch(a, elem, mid + 1, high);
    return binarySearch(a, elem, low, mid - 1);
}

template <typename contType>
void PmergeMe<contType>::binary_insertion(contType &c, int elem, size_t limit) {
	
	size_t loc = binarySearch(c, elem, 0, limit);
	//std::cout << "  insert " << elem << " in loc " << loc << " of " << c << std::endl;;
	c.insert(c.begin() + loc, elem);
}

template <typename contType>
void PmergeMe<contType>::mergeinsert_sort(contType &d) {
	size_t n = d.size();
	if (n == 1) return;

	// 1. pairwise comparison
	contType a; //big
	contType b; //small
	for (size_t i = 0; i < n/2; ++i) {
		if (d[i*2] > d[i*2 + 1]) {
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
	mergeinsert_sort(a);
	for (size_t i = 0; i < n/2; ++i) {
		b[i] = m[a[i]];
	}

	// 3. Insertion
	d = a;
	d.insert(d.begin(), b[0]);
	// t_k in [1..n]. The indices are adjusted to [0..n-1] when used
	unsigned int k = 2; 
	unsigned int upper_half_n = n/2 + n%2;
	while (index_t(k - 1) < upper_half_n) {
		// from: first element of the batch
		size_t from = ::min(index_t(k), upper_half_n) - 1; //idx0
		// u: position of a[from] in d
		size_t u = index_t(k - 1) + from; 

		// k-th batch: 
		// the elements b[t_k, t_k-1, .., t_(k-1)+1]
		// are inserted in that order
		for (size_t i = from; i >= index_t(k - 1) + 1 - 1; --i) { //idx0
			binary_insertion(d, b[i], u - 1);
			// adjust u: position of a[i] in d
			while (d[u] != a[i - 1])
				--u;
		}
		++k;
	}
}

template <typename contType>
contType PmergeMe<contType>::sort(std::list<int> nums) {
	// fill cont
	contType c = contType(nums.begin(), nums.end());
	// sort
	mergeinsert_sort(c);
	return c;
}

// ------------------------------------------------
