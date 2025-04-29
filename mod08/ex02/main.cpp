#include "MutantStack.hpp"
#include <stack>
#include <list>
#include <vector>
#include <iostream>

void test_42() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void test_seq_containers() {
	typedef std::vector<int> Container;
	// typedef std::deque<int> Container;
	// typedef std::list<int> Container;

	Container my_container;
	my_container.push_back(5);
	my_container.push_back(17);
	std::cout << "top: " << my_container.back() << std::endl;
	my_container.pop_back();
	std::cout << "size: " << my_container.size() << std::endl;
	my_container.push_back(3);
	my_container.push_back(5);
	my_container.push_back(737);
	//[...]
	my_container.push_back(0);
	Container::iterator it = my_container.begin();
	Container::iterator ite = my_container.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int, Container> s(my_container);
}

int main()
{
	test_42();
	test_seq_containers();
	return 0;
}