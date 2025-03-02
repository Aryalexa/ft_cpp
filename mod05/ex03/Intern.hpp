#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	enum FormType {
		PRES_F,
		ROB_F,
		SHRU_F,
		N_FORMS
	};
	static const std::string FORM_TYPE_NAMES[N_FORMS];
	FormType stringToFormType(const std::string& type) const;
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target) const;
};

