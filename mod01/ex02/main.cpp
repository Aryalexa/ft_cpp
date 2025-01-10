
#include <string>
#include <iostream>


int main ()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory address of the string: " << &str << std::endl;
	std::cout << "memory address of the string using the pointer: " << stringPTR << std::endl;
	std::cout << "memory address of the string using the reference: " << &stringREF << std::endl;

	std::cout << "value of the string: " << str << std::endl;
	std::cout << "value of the string using the pointer: " << *stringPTR << std::endl;
	std::cout << "value of the string using the reference: " << stringREF << std::endl;

	return 0;

}