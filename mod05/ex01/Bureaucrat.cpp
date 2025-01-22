#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("empty"), _grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	if (_grade < 1)
		throw GradeTooHighException();

}
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
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
// higher = near 1
void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	--_grade;
}
// lower = near 150
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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "";
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return "Grade too high.";
}
const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return "Grade too low.";
}