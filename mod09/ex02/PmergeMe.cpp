#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) 
{ 
    (void)other; 
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other; 
    return (*this); 
}

PmergeMe::~PmergeMe() {}


std::vector<size_t> PmergeMe::j_seq;  // C++98 compatible: inicializa vacío
/**
 * Jacobsthal sequence
 * Jn ​= J(n−1)​ + 2⋅J(n−2)​, n≥2
 *  theory: J0 ​= 0, J1 ​= 1
 *  practical: J0 ​= 1, J1 ​= 3 
 *   (we skip the first 0 and 1 because they don't make sense for our use case, we need to start with 1 to insert the first pending element and 3 to insert the third one before the second one)
 * Jseq = 1, 3, 5, 11, 21, 43...
 */
size_t PmergeMe::j_(size_t n) {
    // First call: initialize with [1, 3]
    if (j_seq.empty()) {
        j_seq.push_back(1);
        j_seq.push_back(3);
    }
    if (n < j_seq.size())
        return j_seq[n];
    while (j_seq.size() <= n)
        j_seq.push_back(j_seq[j_seq.size() - 1] + 2 * j_seq[j_seq.size() - 2]);
    return j_seq[n];
}

/**
 * Function to generate the insertion order based on the Jacobsthal
 * sequence for a given number of pending elements n.
 * 
 * For example, if n = 3, the Jacobsthal numbers are [0, 1, 1, 3],
 * and the insertion order would be [1, 3, 2] (1-based indices).
 */  
std::vector<size_t> PmergeMe::jacobsthal_order(size_t n)
{
    std::vector<size_t> order;
    if (n == 0) 
        return (order);

    // Generate the order
    size_t last = 0;
    for (size_t k = 0; k < n; ++k)
    {
        size_t subgroup_last = j_(k);
        if (subgroup_last > n)
            subgroup_last = n;
        // insert subgroup in reverse order (except the first one) so we can insert them in the correct order later
        for (size_t i = subgroup_last; i > last; --i)
            order.push_back(i);
        last = subgroup_last;
        if (subgroup_last == n)
            break;
    }
    return (order);
}

/**
 * The Ford–Johnson algorithm (merge-insertion sort)
 * Its an algorithm designed to sort a sequence using the fewest comparisons possible
 *
 *   1. Pair elements → larger nb on block goes into “main chain”, smaller goes to “pending”
 *   2. Recursively sort the main chain by pairs
 *   3. Insert pending elements one by one into the main chain
 *
 */ 
void PmergeMe::sort(std::vector<int> &numbers) 
{
    // Base case: if the vector has 0 or 1 element, it's already sorted
    if (numbers.size() <= 1)
        return;

    // 1. Pairs
    std::vector<int> main;
    std::vector<int> pend;
    // [a, b] → a > b → main = [a], pend = [b]
    // [b] (alone → goes to pending) 
    for (size_t i = 0; i < numbers.size(); i += 2)  {
        if (i + 1 < numbers.size()) {
            int a = numbers[i];
            int b = numbers[i + 1];
            if (a < b) 
                std::swap(a, b);
            main.push_back(a);
            pend.push_back(b);
        } else
            pend.push_back(numbers[i]);
    }
    // 2. recursive with main
    sort(main);

    // 3. insert pending into main in jacobsthal order
    std::vector<size_t> order = jacobsthal_order(pend.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i];
        // invalid index (should not happen)
        if (idx == 0 || idx > pend.size()) 
            continue;
        int b = pend[idx - 1];
        // searches the next greater number than b so we can insert it before it
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), b);
        main.insert(pos, b);
    }
    numbers = main;
}


void PmergeMe::sort(std::deque<int> &numbers) 
{
    if (numbers.size() <= 1)
        return;

    std::deque<int> main;
    std::deque<int> pend;

    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (i + 1 < numbers.size()) {
            int a = numbers[i];
            int b = numbers[i + 1];
            if (a < b) 
                std::swap(a, b);
            main.push_back(a);
            pend.push_back(b);
        } else
            pend.push_back(numbers[i]);
    }

    sort(main);

    std::vector<size_t> order = jacobsthal_order(pend.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i];
        if (idx == 0 || idx > pend.size())
            continue;
        int b = pend[idx - 1];
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), b);
        main.insert(pos, b);
    }

    numbers = main;
}