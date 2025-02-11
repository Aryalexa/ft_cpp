#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    const std::string _target;

    ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;
};



