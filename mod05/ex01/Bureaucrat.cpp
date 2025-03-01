#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():
	_name("empty"), _grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string name, int grade):
	_name(name), _grade(grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	if (_grade < 1)
		throw GradeTooHighException();

}
Bureaucrat::Bureaucrat(const Bureaucrat &other):
	_name(other._name), _grade(other._grade)
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// cannot re-assign the const member!
	}
	return *this;
}
Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

// highest 1
// lowest 150
void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	--_grade;
}

// highest 1
// lowest 150
void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	++_grade;
}
void Bureaucrat::signForm(Form &f) const
{
	try
	{
		f.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " couldn't sign " << f << " because " << e.what() << std::endl;
		return;
	}
	std::cout << *this << " signed " << f << std::endl;
	
}

const std::string Bureaucrat::toString() const
{
	std::ostringstream ss;

	ss << getName() << ", bureaucrat grade " << getGrade() << ",";
	return ss.str();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.toString();
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}
