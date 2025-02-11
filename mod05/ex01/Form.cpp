#include "Form.hpp"

Form::Form(): _name("empty"), _isSigned(false), _gradeToSign(0), _gradeToExec(0)
{
	// not valid
}
Form::Form(std::string name, int gradeToSign, int gradeToExec):
	_name(name), _isSigned(false), 
	_gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other): 
	_name(other._name), _isSigned(other._isSigned), 
	_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		//not valid
	}
	return *this;
}
Form::~Form()
{
}

const std::string &Form::getName() const
{
	return _name;
}
bool Form::getIsSigned() const
{
	return _isSigned;
}
int Form::getGradetoSign() const
{
	return _gradeToSign;
}
int Form::getGradetoExec() const
{
	return _gradeToExec;
}

const char* Form::GradeTooHighException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	return "Grade too high.";
}
const char* Form::GradeTooLowException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	return "Grade too low.";
}

const std::string Form::toString() const
{
	std::ostringstream ss;

	std::string s = getIsSigned()? "signed" : "not signed";
	ss << getName() << " form"
		<< " (" << s << "/S:"<< getGradetoSign() << "/E:" << getGradetoExec() << ")";
	return ss.str();
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.toString();
	return out;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (_isSigned) return;
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}
