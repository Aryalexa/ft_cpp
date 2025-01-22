#pragma once

#include <string>
#include <iostream>
#include <exception>

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
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &f) const;

	class GradeTooHighException : public std::exception {
		const char* what() const _NOEXCEPT;
	};
	class GradeTooLowException : public std::exception {
		const char* what() const _NOEXCEPT;
	};

};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
