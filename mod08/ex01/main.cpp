#include "Span.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib> // for std::rand and std::srand
#include <ctime> // for std::time

void test_42()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "------" << std::endl;
	sp.display();
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;
}

void test_ro4() {
	Span sp = Span(3);
	sp.addNumber(3);
	sp.addNumber(3);
	sp.addNumber(17);

	//SCOPE
    {
        Span tmp = sp;
        Span test(tmp);
    }
	std::cout << "------" << std::endl;
	sp.display();
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;	
}

void test_alot() {
	size_t N = 10000;
	Span sp = Span(N);

	srand(time(NULL)); // Seed the random number generator (when null is passed, it uses the current time)
    for (size_t i = 0; i < N; i++)
    {
        const int value = rand() % N;
		sp.addNumber(value);
    }
	std::cout << "------" << std::endl;
	std::cout << "Len: " << N << std::endl;
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;		
}

void test_range_of_iter() {
	std::cout << "------" << std::endl;

	size_t N = 10000;
	Span sp = Span(N);

	sp.display();

	sp.addNumber(3);

	int arr1[] = {1,2,3};
	std::list<int> new_nums(arr1, arr1 + sizeof(arr1) / sizeof(int));
	sp.addNumbers(new_nums.begin(), new_nums.end());

	sp.display();


	int arr2[] = {11,22,33,44};
	sp.addNumbers(arr2, arr2 + sizeof(arr2) / sizeof(int));

	sp.display();

}

int main() {
	test_42();
	test_ro4();
	test_alot();

	test_range_of_iter();

	return 0;
}
