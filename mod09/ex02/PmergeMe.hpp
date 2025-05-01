
#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <list>
#include <map>
#include <vector>
#include <algorithm>


template <typename C>
void print_nums(const std::string &msg, const C &nums) {
	std::cout << msg << "\t";
	typename C::const_iterator it;
	for (it = nums.begin(); it!=nums.end(); ++it) {
		std::cout << (*it) << " ";
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
