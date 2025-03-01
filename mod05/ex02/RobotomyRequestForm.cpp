#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
    AForm("RobotomyRequestForm", 72, 45), _target("no-target")
{
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : 
    AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
    AForm(other), _target(other._target)
{
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        // nonsense
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.
void RobotomyRequestForm::doExecute(Bureaucrat const & executor) const
{
    (void) executor;
    std::cout << "* drilling noises *" << std::endl;

    int randomNumber = rand() % 2;
    if (randomNumber == 0)
    {
        std::cout << _target << " has been succesfully robotomized.✅" << std::endl;
        return ;
    }
    std::cout << _target << " could not be robotomized.❌" << std::endl;
    throw std::runtime_error("Robotomy failed.");
}
    
