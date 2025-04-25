#include <string>
#include <iostream>
#include "Array.hpp"


void test_int()
{
	using std::cout;
	using std::endl;
	cout << "----- int ------" << endl;

	cout << "🐡 empty array" << endl;
	try {
		int * a = new int(); //then display *a.
		cout << *a << endl;
		cout << a[0] << endl;
		delete a;

		Array<int> arr_int =  Array<int>();
		cout << "len: " << arr_int.size() << endl;
		cout << arr_int[0] << endl;
	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}
	try {
		Array<int> arr_parm =  Array<int>(0);
		cout << "len: " << arr_parm.size() << endl;
		cout << arr_parm[0] << endl;
	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}

	cout << "🐡 construct and copies" << endl;
	try {
		Array<int> arr_int = Array<int>(3);	
		arr_int[1] = 1;
		Array<int> arr_int2 = Array<int>(arr_int);
		arr_int2[2] = 2;
		print_arr(arr_int);
		print_arr(arr_int2);

		cout << "--" << endl;

		arr_int2 = arr_int;
		print_arr(arr_int);
		print_arr(arr_int2);
	
		cout << "--" << endl;

		arr_int2[1] = 2;
		print_arr(arr_int);
		print_arr(arr_int2);

	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}


}

void test_str()
{
	using std::cout;
	using std::endl;
	using std::string;
	cout << "----- str ------" << endl;

	cout << "🐡 empty array" << endl;
	try {
		string * a = new string(); //then display *a.
		cout << *a << endl;
		cout << a[0] << endl;
		delete a;

		Array<string> arr_def =  Array<string>();
		cout << "len: " << arr_def.size() << endl;
		cout << arr_def[0] << endl;
	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}
	try {
		Array<string> arr_parm =  Array<string>(0);
		cout << "len: " << arr_parm.size() << endl;
		cout << arr_parm[0] << endl;
	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}

	cout << "🐡 construct and copies" << endl;
	try {
		Array<string> arr_1 = Array<string>(3);	
		arr_1[0] = "hi1";
		arr_1[1] = "hi2";
		arr_1[2] = "hi3";
		Array<string> arr_2 = Array<string>(arr_1);
		arr_2[2] = "hello";
		print_arr(arr_1);
		print_arr(arr_2);

		cout << "--" << endl;

		arr_2 = arr_1;
		print_arr(arr_1);
		print_arr(arr_2);
	
		cout << "--" << endl;

		arr_2[1] = "bye";
		print_arr(arr_1);
		print_arr(arr_2);


		cout << arr_1[-1] << endl;

	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}


}

int main() {
	test_int();
	test_str();
	
}
