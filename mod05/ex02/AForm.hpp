#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExec;

	AForm();
	AForm &operator=(const AForm &other);

protected:
	void check_exec_requirements(Bureaucrat const & executor) const;
	virtual void doExecute(Bureaucrat const & executor) const = 0;

public:
	AForm(std::string name, int gradeToSign, int gradeToExec);
	AForm(const AForm &other);
	virtual ~AForm();

	void beSigned(const Bureaucrat &b);
	void execute(Bureaucrat const & executor);

	// getters
	const	std::string &getName() const;
	bool	getIsSigned() const;
	int		getGradetoSign() const;
	int		getGradetoExec() const;
	const	std::string toString() const;

	// exceptions
	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};
	class NotSignedException : public std::exception {
		const char* what() const throw() ;
	};
};
std::ostream &operator<<(std::ostream &out, const AForm &f);
