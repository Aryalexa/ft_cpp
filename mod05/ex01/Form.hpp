#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExec;

	Form();
	Form &operator=(const Form &other);

public:
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(const Form &other);
	~Form();

	void beSigned(const Bureaucrat &b);

	// getters
	const std::string &getName() const;
	bool	getIsSigned() const;
	int		getGradetoSign() const;
	int		getGradetoExec() const;
	const std::string toString() const;

	// exceptions
	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};
};
std::ostream &operator<<(std::ostream &out, const Form &f);
