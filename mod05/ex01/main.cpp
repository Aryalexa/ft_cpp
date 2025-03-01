
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	using std::cout;
	using std::endl;
	try
	{
		/* do some stuff with bureaucrats */
		Bureaucrat b1("Fe", 34);
		cout << b1 << " created." << endl;
		b1.decrementGrade();
		cout << b1 << " modified." << endl;
		
		Form f1("New Park", 30, 20);
		cout << "New form: " << f1 << endl;
		Form f2("New Trashcan", 122, 80);
		cout << "New form: " << f2 << endl;
		cout << b1 << " tries to sign " << f1 << "..." << endl;
		b1.signForm(f1);
		cout << b1 << " tries to sign " << f2 << "..." << endl;
		b1.signForm(f2);
		
	}
	catch (std::exception & e)
	{
		/* handle exception */
		cout << "Exception: " << e.what() << endl;
	}
	return 0;
}