
#include "Bureaucrat.hpp"

int main()
{
	using std::cout;
	using std::endl;
	try
	{
		/* do some stuff with bureaucrats */
		Bureaucrat b1("Fe", 34);
		cout << b1 << " created." << endl;
		cout << "we try to decrement their grade..." << endl;
		b1.decrementGrade();
		cout << b1 << " modified." << endl;
		cout << "we try to increment their grade..." << endl;
		b1.incrementGrade();
		cout << b1 << " modified." << endl;
		
		Bureaucrat b3("Jen", 1);
		cout << b3 << " created." << endl;
		cout << "we try to increment their grade..." << endl;
		b3.incrementGrade(); // too high
	}
	catch (std::exception & e)
	{
		/* handle exception */
		cout << "Exception: " << e.what() << endl;
	}

	return 0;
}