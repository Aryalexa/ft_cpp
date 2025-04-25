#include <cctype>
#include <iostream>

template <typename T>
void my_print(T v) {
	std::cout << v << std::endl;
}

template <typename T>
void gt5(T a) {
	::my_print(a > 5);
}


template <typename T, typename F>
void iter(T *arr, size_t len, F func) {
	for (size_t i = 0; i < len; ++i)
		(*func)(arr[i]);
}