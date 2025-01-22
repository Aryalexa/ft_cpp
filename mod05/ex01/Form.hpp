#pragma once

#include <string>
#include <iostream>

class Bureaucrat;
class Form
{
private:
	const std::string _name;
	bool _isSigned;
	int _gradeToSign;
	int _gradeToExec;

	Form();
	Form &operator=(const Form &other);
public:
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(const Form &other);
	~Form();

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradetoSign() const;
	int getGradetoExec() const;

	void beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception {
		const char* what() const _NOEXCEPT;
	};
	class GradeTooLowException : public std::exception {
		const char* what() const _NOEXCEPT;
	};
};
std::ostream &operator<<(std::ostream &out, const Form &f);
