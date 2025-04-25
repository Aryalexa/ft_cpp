#include <string>
#include <iostream>
#include "iter.hpp"

int main() {
	std::cout << "int" << "----------" << std::endl;
	int arr_int3[3] = {1, 5 ,10};
	::iter(arr_int3, 3, ::my_print<int>);
	::iter(arr_int3, 3, gt5<int>);

	std::cout << "int" << "----------" << std::endl;
	int *arr_int = new int[3];
	arr_int[0] = 4;
	arr_int[1] = 8;
	arr_int[2] = 16;
	::iter(arr_int, 3, my_print<int>);
	::iter(arr_int, 3, gt5<int>);
	delete [] arr_int;

	std::cout << "string" << "----------" << std::endl;
	std::string *arr_str = new std::string[3];
	arr_str[0] = "oso1";
	arr_str[1] = "oso2";
	arr_str[2] = "oso3";
	::iter(arr_str, 3, my_print<std::string>);
	delete [] arr_str;

	std::cout << "char" << "----------" << std::endl;
	std::string str = "hola";
	::iter(str.c_str(), str.length(), my_print<char>);

}
