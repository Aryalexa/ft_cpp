#pragma once

#include "AForm.hpp"
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <unistd.h> // sleep()

class PresidentialPardonForm : public AForm
{
private:
    const std::string _target;

    PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

protected:
    void doExecute() const;

public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
};



