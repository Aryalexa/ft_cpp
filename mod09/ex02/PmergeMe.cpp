
#include "PmergeMe.hpp"

size_t min(size_t n1, size_t n2) {
	if (n1 < n2)
		return n1;
	return n2;
}

/**
 * t_k = ( 2^(k+1) + (-1)^k ) / 3
 */
unsigned int index_t(unsigned int k) {
	using std::pow;
	return ( pow(2, k + 1) + pow(-1, k)) / 3;
}

// ------------------------------------------------
