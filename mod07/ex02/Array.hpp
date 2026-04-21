#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *arr;
	unsigned int len;
public:
	Array(): arr(0), len(0) {}
	Array(unsigned int n) : arr(n ? new T[n] : 0), len(n) {}
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array() {
		if (arr)
			delete [] arr;
	}

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	unsigned int size() const {
		return len;
	}

};


template <typename T>
Array<T>::Array(const Array<T> &other): arr(other.len ? new T[other.len] : 0), len(other.len)
{
	for (unsigned int i = 0; i < len; ++i)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		/** if we already have values, we must overwrite them */
		T *tmp = other.len ? new T[other.len] : 0;
		for (unsigned int i = 0; i < other.len; ++i)
			tmp[i] = other.arr[i];
		if (arr)
			delete [] arr;
		arr = tmp;
		len = other.len;
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < len)
		return arr[index];
	throw std::out_of_range("Exception: index out of bounds");
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index < len)
		return arr[index];
	throw std::out_of_range("Exception: index out of bounds");
}

template <typename T>
void print_arr(const Array<T> &arr)
{
	using std::cout;
	using std::endl;
	for (unsigned int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i];
		if (i != arr.size() - 1)
			cout << ",";
	}
	cout << endl;
}