
#include "AForm.hpp"

AForm::AForm(): _name("empty"), _isSigned(false), _gradeToSign(0), _gradeToExec(0)
{
	// not valid
}
AForm::AForm(std::string name, int gradeToSign, int gradeToExec):
	_name(name), _isSigned(false), 
	_gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other): 
	_name(other._name), _isSigned(other._isSigned), 
	_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		//not valid
	}
	return *this;
}
AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
	return _name;
}
bool AForm::getIsSigned() const
{
	return _isSigned;
}
int AForm::getGradetoSign() const
{
	return _gradeToSign;
}
int AForm::getGradetoExec() const
{
	return _gradeToExec;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}
const char* AForm::NotSignedException::what() const throw()
{
	return "Not signed.";
}


const std::string AForm::toString() const
{
	std::ostringstream ss;

	std::string s = getIsSigned()? "signed" : "not signed";
	ss << getName() << " Form"
		<< " (" << s << "/S:"<< getGradetoSign() << "/E:" << getGradetoExec() << ")";
	return ss.str();
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.toString();
	return out;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (_isSigned) return;
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor)
{
	check_exec_requirements(executor);
	doExecute();
}

void AForm::check_exec_requirements(Bureaucrat const & executor) const
{
	//check the form is signed  
	if (!_isSigned)
		throw NotSignedException();
    //check the grade of the bureaucrat is high enough. 
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
}
