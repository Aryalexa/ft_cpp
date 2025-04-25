#pragma once

#include <string>
#include <iostream>

template <typename T>
class Array
{
private:
	T *arr;
	unsigned int len;
public:
	Array(): len(0) {}
	Array(unsigned int n) : arr(new T[n]), len(n) {}
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array() {
		if (len > 0)
			delete [] arr;
	}

	T &operator[](unsigned int index);
	unsigned int size() const {
		return len;
	}

};


template <typename T>
Array<T>::Array(const Array<T> &other): arr(new T[other.len]), len(other.len)
{
	for (unsigned int i = 0; i < len; ++i)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		if (len > 0)
			delete [] arr;
		len = other.len;
		arr = new T[len];
		for (unsigned int i = 0; i < len; ++i)
			arr[i] = other.arr[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < len)
		return arr[index];
	throw std::runtime_error("Exception: index out of bounds");
	//throw std::exception();
}

template <typename T>
void print_arr(Array<T> arr)
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