
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	using std::cout;
	using std::endl;
	try
	{
		/* do some stuff with bureaucrats */
		Bureaucrat sam("Sam", 33);
		cout << sam << " created." << endl;
		Bureaucrat gabi("Gabi", 140);
		cout << gabi << " created." << endl;

		AForm *form = NULL;
		
		cout << endl;
		form = new ShrubberyCreationForm("Saint Williams");
		cout << "New form: " << *form << endl;
		cout << sam << " tries to sign " << *form << endl;
		sam.signForm(*form);
		cout << sam << " tries to execute " << *form << endl;
		sam.executeForm(*form);

		cout << endl;
		form = new ShrubberyCreationForm("NOTsigned");
		cout << "New form: " << *form << endl;
		cout << sam << " tries to execute " << *form << endl;
		sam.executeForm(*form);

		cout << endl;
		form = new ShrubberyCreationForm("Peterson");
		cout << "New form: " << *form << endl;
		cout << gabi << " tries to sign " << *form << endl;
		gabi.signForm(*form);
		cout << gabi << " tries to execute " << *form << endl;
		gabi.executeForm(*form);

		delete form;

	}
	catch (std::exception & e)
	{
		/* handle exception */
		cout << "Exception: " << e.what() << endl;
	}

	return 0;
}