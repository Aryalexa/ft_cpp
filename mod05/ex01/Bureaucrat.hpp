#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <sstream>

class Form;
class Bureaucrat
{
private:
	const std::string _name;
	int _grade; // [1-150]

	Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &other);

public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;
	const std::string toString() const;

	void incrementGrade();
	void decrementGrade();
	void signForm(Form &f) const;

	class GradeTooHighException : public std::exception {
		const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
	};
	class GradeTooLowException : public std::exception {
		const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
	};

};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
