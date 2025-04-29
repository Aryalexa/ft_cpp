
#include <iostream>
#include <string>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>

int main() {
	using std::cout;
	using std::endl;

	std::list<int> myl;
	myl.push_back(1);
	myl.push_back(25);
	myl.push_back(50);
	myl.push_back(25);
	easyfind_test("list", myl, 23, 25);

	std::deque<int> myd;
	myd.push_back(5);
	myd.push_back(4);
	myd.push_back(3);
	myd.push_back(3);
	easyfind_test("deque", myd, 1, 3);

	std::vector<int> myv;
	myv.push_back(0);
	myv.push_back(100);
	myv.push_back(-1);
	myv.push_back(99);
	easyfind_test("vector", myv, 23, 99);

	std::set<int> mySet;
	mySet.insert(5);
	mySet.insert(15);
	mySet.insert(25);
	mySet.insert(35);
	easyfind_test("set", mySet, 10, 5);

}