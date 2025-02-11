#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("ShrubberyCreationForm", 145, 137), _target("null")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : 
    AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
    AForm(other), _target(other._target)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        // no sense
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    check_exec_requirements(executor);
    //todo
    /**
     * ALT 1
     * 
     * 
     base
     -----
     - exec = 0
     - exec_req {req}

     deriv
     -----
     - exec { exec_req(), real exec}

     */
    /**
     * ALT 2
     * 
     * 
     base
     -----
     - exec { reqs, exec_concrete() }
     - exec_concrete = 0

     deriv
     -----
     - exec_concrete {}

     */
}
