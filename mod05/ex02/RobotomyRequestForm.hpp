#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    const std::string _target;

    RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

protected:
    void doExecute(Bureaucrat const & executor) const;

public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();
};



