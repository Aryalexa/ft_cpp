/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:50:10 by usuario           #+#    #+#             */
/*   Updated: 2025/12/04 12:26:54 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe &other) 
{ 
    (void)other; 
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other; 
    return (*this); 
}

PmergeMe::~PmergeMe() {
    
}

/*                          Jacobsthal sequence
*                       J0​=0, J1​=1, Jn​=J(n−1)​+2 ⋅Jn−2​, n≥2
*                          0, 1, 1, 3, 5, 11, 21, 43...
*
*   - Returns an index vector indicating the order in which elements 
*      should be inserted in the Ford-Johnson merge-insertion algorithm
*   - The order is NOT 1, 2, 3, 4, 5… but a special order based on Jacobsthal, 
*    
*      ----- Inserting the elements in this specific order improves the number  -----
*                     --------   of comparisons -------
*       
*/ 

std::vector<size_t> PmergeMe::jacobsthal_order(size_t n)
{
    // Will store the insertion order
    //[1, 3, 5, 11, 21…]
    std::vector<size_t> order;
    if (n == 0) 
        return (order);

    std::vector<size_t> jac;

    // We start with 1 and 3, using this sequence 'Jn​=J(n−1)​+2 ⋅Jn−2' (new number = last + 2 × second last - 2)
    // Stop when the new number >= size of pending elements
    // jac = [1, 3, 5]
    jac.push_back(1);
    jac.push_back(3);
    while (jac.back() < n)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);

    // Loops through each number on the Jacobsthal sequence
    size_t last = 0;
    for (size_t k = 0; k < jac.size(); ++k)
    {
        size_t j = jac[k];
        // Last jac number may check > n, we correct it
        if (j > n)
            j = n;
        // Sequence added in reverse (descending) order because
        // we still need to insert every index missing from sequence but in reverse:
        // order = [1, 3, 2, 5, 4]
        for (size_t i = j; i > last; --i)
            order.push_back(i);
        last = j;
        if (j == n)
            break;
    }
    return (order);
}

/*          The Ford–Johnson algorithm (a.k.a. merge-insertion sort)
* Its an algorithm designed to sort a sequence using the fewest comparisons possible
*
*           1. Pair elements → larger nb on block goes into “main chain”, smaller goes to “pending”
*           2. Recursively sort the main chain by pairs
*           3. Insert pending elements one by one into the main chain
*
*/ 

void PmergeMe::sort(std::vector<unsigned int> &v) 
{
    // [7,3,9,1,5]
    if (v.size() <= 1)
        return;

    std::vector<unsigned int> main;
    std::vector<unsigned int> pend;

    // Pairs
    // [7, 3]
    // [9, 1]
    // [5] (alone-> goes to pending)

    for (size_t i = 0; i < v.size(); i += 2) 
    {
        if (i + 1 < v.size()) 
        {
            unsigned int a = v[i];
            unsigned int b = v[i + 1];
            if (a < b) 
                std::swap(a, b);
            // main = [7, 9]
            // pend = [3, 1, 5]
            main.push_back(a);
            pend.push_back(b);
        } 
        else
            pend.push_back(v[i]);
    }

    // recursive
    sort(main);

    // main already sorted: [7, 9]
    // pending unsorted: [3, 1, 5]
    std::vector<size_t> order = jacobsthal_order(pend.size());
    // if pend.size() = 3 -> [1, 3, 2] jac order
    // loops for size() and inserts index in jac order
        //      idx=1 → pend[0] → 3  
        //      idx=3 → pend[2] → 5  
        //      idx=2 → pend[1] → 1 

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i];
        if (idx == 0 || idx > pend.size())
            continue;
        unsigned int x = pend[idx - 1];
        // searches the next greater number than x so we can insert it before it
            // main = [10, 20, 30, 50]
            // x = [25] -> before 30
        std::vector<unsigned int>::iterator pos = std::lower_bound(main.begin(), main.end(), x);
        main.insert(pos, x);
    }
    v = main;
}


void PmergeMe::sort(std::deque<unsigned int> &v) 
{
    if (v.size() <= 1)
        return;

    std::deque<unsigned int> main;
    std::deque<unsigned int> pend;


    for (size_t i = 0; i < v.size(); i += 2) 
    {
        if (i + 1 < v.size()) 
        {
            unsigned int a = v[i];
            unsigned int b = v[i + 1];
            if (a < b) 
                std::swap(a, b);
            main.push_back(a);
            pend.push_back(b);
        }
        else
            pend.push_back(v[i]);
    }

    sort(main);

    std::vector<size_t> order = jacobsthal_order(pend.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i];
        if (idx == 0 || idx > pend.size())
            continue;
        unsigned int x = pend[idx - 1];
        std::deque<unsigned int>::iterator pos = std::lower_bound(main.begin(), main.end(), x);
        main.insert(pos, x);
    }

    v = main;
}