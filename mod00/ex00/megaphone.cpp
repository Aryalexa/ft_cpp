#include <string>
#include <cctype>
#include <iostream>


std::string toUpper(std::string s)
{
	for (size_t i = 0; i < s.length(); ++i)
		s[i] = std::toupper(s[i]);
	return s;
}

int main(int argc, char *argv[])
{
	const std::string DFT_MSG = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";	
	if (argc == 1)
		std::cout << DFT_MSG; 
	for (int i = 1; i < argc; i++)
		std::cout << toUpper(argv[i]);
	std::cout << std::endl;
	return 0;
}