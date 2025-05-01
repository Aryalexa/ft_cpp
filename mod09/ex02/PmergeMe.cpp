
#include "PmergeMe.hpp"

static size_t min(size_t n1, size_t n2) {
	if (n1 < n2)
		return n1;
	return n2;
}

/**
 * t_k = ( 2^(k+1) + (-1)^k ) / 3
 */
static unsigned int index_t(unsigned int k) {
	using std::pow;
	return ( pow(2, k + 1) + pow(-1, k)) / 3;
}

// ------------------------------------------------

const std::string PmergeMe1::CONTAINER_NAME = "vector";

/**
 * returns position to insert
 * - low and high are both included in the search.
 */
int PmergeMe1::binarySearch(const PmergeMe1::contType &a, int elem, int low, int high)
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

void PmergeMe1::binary_insertion(contType &c, int elem, size_t limit) {
	
	size_t loc = binarySearch(c, elem, 0, limit);
	//std::cout << "  insert " << elem << " in loc " << loc << " of " << c << std::endl;;
	c.insert(c.begin() + loc, elem);
}

void PmergeMe1::mergeinsert_sort(contType &d) {
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

void PmergeMe1::sort(std::list<int> nums) {
	// fill cont
	contType c = contType(nums.begin(), nums.end());
	// sort
	mergeinsert_sort(c);
	print_nums("result", c);

}

// ------------------------------------------------
