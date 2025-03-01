#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <sstream>

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

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
		// const char* what() const noexcept; // c++11+
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
