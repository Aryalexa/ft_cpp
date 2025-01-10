
#include <string>
#include <iostream>


int main ()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory address of the string: " << &str << std::endl;
	std::cout << "memory address held by the pointer: " << stringPTR << std::endl;
	std::cout << "memory address held by the reference: " << &stringREF << std::endl;

	std::cout << "value of the string: " << str << std::endl;
	std::cout << "value pointed to by the pointer: " << *stringPTR << std::endl;
	std::cout << "value pointed to by the reference: " << stringREF << std::endl;

	return 0;

}