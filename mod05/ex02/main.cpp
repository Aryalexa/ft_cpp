
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShF()
{
	using std::cout;
	using std::endl;
	try
	{
		/* do some stuff with bureaucrats */
		cout << "🔅" << endl;
		Bureaucrat sam("Sam", 33);
		cout << sam << " created." << endl;
		Bureaucrat gabi("Gabi", 140);
		cout << gabi << " created." << endl;

		AForm *form = NULL;
		
		cout << endl;
		form = new ShrubberyCreationForm("Home");
		cout << "New form: " << *form << endl;
		cout << sam << " tries to sign " << *form << endl;
		sam.signForm(*form);
		cout << sam << " tries to execute " << *form << endl;
		sam.executeForm(*form);

		cout << endl;
		form = new ShrubberyCreationForm("Office");
		cout << "New form: " << *form << endl;
		cout << sam << " tries to execute " << *form << endl;
		sam.executeForm(*form);

		cout << endl;
		form = new ShrubberyCreationForm("Hospital");
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
}

void testRobF()
{
	using std::cout;
	using std::endl;
	srand(time(0) + getpid());
	try
	{
		/* do some stuff with bureaucrats */
		cout << "🔅" << endl;
		Bureaucrat shelly("Shelly", 40);
		cout << shelly << " created." << endl;

		AForm *form = NULL;
		
		cout << endl;
		form = new RobotomyRequestForm("Randy");
		cout << "New form: " << *form << endl;
		cout << shelly << " tries to sign " << *form << endl;
		shelly.signForm(*form);

		for (int i = 0; i < 5; ++i)
		{
			cout << "Try " << i + 1 << endl; 
			cout << shelly << " tries to execute " << *form << endl;
			shelly.executeForm(*form);
		}

		delete form;
	}
	catch (std::exception & e)
	{
		/* handle exception */
		cout << "Exception: " << e.what() << endl;
	}
}
void testPresF()
{
	using std::cout;
	using std::endl;
	try
	{
		/* do some stuff with bureaucrats */
		cout << "🔅" << endl;
		Bureaucrat rita("Rita", 3);
		cout << rita << " created." << endl;
		Bureaucrat taylor("Taylor", 7);
		cout << taylor << " created." << endl;

		AForm *form = NULL;
		
		cout << endl;
		form = new PresidentialPardonForm("Jake");
		cout << "New form: " << *form << endl;
		cout << rita << " tries to sign " << *form << endl;
		rita.signForm(*form);
		cout << rita << " tries to execute " << *form << endl;
		rita.executeForm(*form);

		cout << endl;
		form = new PresidentialPardonForm("Lindsey");
		cout << "New form: " << *form << endl;
		cout << rita << " tries to execute " << *form << endl;
		rita.executeForm(*form);

		cout << endl;
		form = new PresidentialPardonForm("Logan");
		cout << "New form: " << *form << endl;
		cout << taylor << " tries to sign " << *form << endl;
		taylor.signForm(*form);
		cout << taylor << " tries to execute " << *form << endl;
		taylor.executeForm(*form);

		delete form;
	}
	catch (std::exception & e)
	{
		/* handle exception */
		cout << "Exception: " << e.what() << endl;
	}
}
int main()
{
	testShF();
	testRobF();
	testPresF();
	return 0;
}