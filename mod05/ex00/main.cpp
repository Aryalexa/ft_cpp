
#include "Bureaucrat.hpp"

int main()
{

	try
	{
		/* do some stuff with bureaucrats */
		Bureaucrat b1("Fe", 34);
		std::cout << b1 << " created." << std::endl;
		b1.decrementGrade();
		std::cout << b1 << " modified." << std::endl;
		
		Bureaucrat b2("Elle", 144);
		std::cout << b2 << " created." << std::endl;
		Bureaucrat b3("Jen", 1);
		std::cout << b3 << " created." << std::endl;
		b3.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}