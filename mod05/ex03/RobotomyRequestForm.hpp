#pragma once

#include "AForm.hpp"
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <unistd.h> // sleep()

class RobotomyRequestForm : public AForm
{
private:
    const std::string _target;

    RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

protected:
    void doExecute() const;

public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();
};



