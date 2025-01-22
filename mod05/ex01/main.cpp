
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	try
	{
		/* do some stuff with bureaucrats */
		Bureaucrat b1("Fe", 34);
		std::cout << b1 << " created." << std::endl;
		b1.decrementGrade();
		std::cout << b1 << " modified." << std::endl;
		
		Form f1("New Park", 30, 20);
		std::cout << "new form: " << f1 << std::endl;
		Form f2("New Trash", 122, 80);
		std::cout << "new form: " << f2 << std::endl;
		b1.signForm(f1);
		b1.signForm(f2);
		
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}