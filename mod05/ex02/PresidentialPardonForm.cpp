#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
    AForm("PresidentialPardonForm", 25, 5), _target("no-target")
{
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : 
    AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
    AForm(other), _target(other._target)
{
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        // nonsense
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Informs that <target> has been pardoned by Zaphod Beeblebrox.
void PresidentialPardonForm::doExecute() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
    
