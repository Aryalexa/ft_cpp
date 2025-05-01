
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
void print_nums(const std::string &msg, const C &nums) {
	std::cout << msg << "\t";
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
 * - low and high are both included in the search.
 */
int PmergeMe1::binarySearch(PmergeMe1::contType a, int elem, int low, int high)
{
	std::cout << "   binSearch " << elem 
		<< " in " << a << " [" << low << "," << high << "]" << std::endl;
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
	std::cout << "  insert " << elem << " in loc " << loc << " of " << c << std::endl;;
	c.insert(c.begin() + loc, elem);
	std::cout << "   out" << std::endl;
	return c;
}

PmergeMe1::contType PmergeMe1::mergeinsert_sort(contType d) {
	using std::cout;
	using std::endl;
	size_t n = d.size();
	cout << "n: " << n << "-------" << endl;
	if (n == 1) return d;
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

	print_nums("a big  :", a);
	print_nums("b small:", b);
	// 2. Recursion and renaming
	std::map<int, int> m;
	for (size_t i = 0; i < n/2; ++i) {
		m[a[i]] = b[i];
	}
	a = mergeinsert_sort(a);
	for (size_t i = 0; i < n/2; ++i) {
		b[i] = m[a[i]];
	}
	cout << "n: " << n << "-------" << endl;
	// 3. Insertion
	d = a;
	d.insert(d.begin(), b[0]);
	print_nums("a:", a);
	print_nums("b:", b);
	print_nums("ini", d);
	unsigned int k = 2;
	unsigned int upper_half_n = n/2 + n%2;
	// k-th batch: the elements b[t_k, t_k-1, .., t_(k-1)+1]
	// are inserted in that order
	cout << " k:" << k 
			<< ", t_(k-1):" << index_t(k-1) 
			<< " < upHn:" << upper_half_n
			<< endl;
	while (index_t(k - 1) < upper_half_n) {
		cout << " in" << endl;
		// from: first element of the batch
		size_t from = ::min(index_t(k), upper_half_n) - 1; //idx0
		// u: position of a[from] in d
		size_t u = index_t(k - 1) + from; 
		cout << " from " << from << " down to " << index_t(k - 1) + 1 - 1 << endl;
		for (size_t i = from; i >= index_t(k - 1) + 1 - 1; --i) { //idx0
			cout << "  i=" << i << ". insert b[i]="<< b[i]<< endl;
			cout << "  a[i]="<< a[i] << " in d: " << u << endl;
			d = binary_insertion(d, b[i], u - 1);
			print_nums("  new", d);	
			// adjust u: position of a[i] in d
			while (d[u] != a[i - 1])
				--u;
		}
		++k;
		cout << " k:" << k 
			<< ", t_(k-1):" << index_t(k-1) 
			<< " < upHn:" << upper_half_n
			<< endl;
	}
	print_nums("fin", d);
	return d;
}

void PmergeMe1::sort(std::list<int> nums) {
	// fill cont
	contType c = contType(nums.begin(), nums.end());
	// sort
	c = mergeinsert_sort(c);
	print_nums("result", c);

}
