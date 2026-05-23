#include <cctype>
#include <iostream>

template <typename T>
void my_print(const T &v) {
	std::cout << v << std::endl;
}

template <typename T>
void gt5(const T &a) {
	::my_print(a > 5);
}

template <typename T>
void increment(T &v) {
	v++;
}


template <typename T, typename F>
void iter(T *arr, size_t len, F func) {
	for (size_t i = 0; i < len; ++i)
		func(arr[i]);
}

template <typename T, typename F>
void iter(const T *arr, size_t len, F func) {
	for (size_t i = 0; i < len; ++i)
		func(arr[i]);
}
