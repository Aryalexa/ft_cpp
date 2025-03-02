
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	using std::cout;
	using std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* rrf = NULL;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		cout << "Intern made " << *rrf << endl;
		delete rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		cout << "Intern made " << *rrf << endl;
		delete rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
		cout << "Intern made " << *rrf << endl;
		delete rrf;

		rrf = someRandomIntern.makeForm("robot request", "Intern");
		cout << "Intern made " << *rrf << endl;
		delete rrf;

	}
	catch (std::exception & e)
	{
		/* handle exception */
		cout << "Exception: " << e.what() << endl;
	}

	return 0;
}