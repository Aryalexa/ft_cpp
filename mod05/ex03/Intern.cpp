#include "Intern.hpp"

const std::string Intern::FORM_TYPE_NAMES[Intern::N_FORMS] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

Intern::Intern()
{
}
Intern::Intern(const Intern &other)
{
	(void)other;
}
Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		//nothing
	}
	return *this;
}
Intern::~Intern()
{
}

Intern::FormType Intern::stringToFormType(const std::string& type) const
{
	for (int i = 0; i < N_FORMS; ++i)
	{
		if (type == FORM_TYPE_NAMES[i])
			return static_cast<FormType>(i); // check at compilation time
	}
	std::ostringstream help_msg;
	help_msg << "Available types:\n";
	for (int i = 0; i < N_FORMS; ++i)
		help_msg << "- " << FORM_TYPE_NAMES[i]<< std::endl;
	throw std::runtime_error("Form not found. " + help_msg.str());
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	FormType ftype = stringToFormType(formName);
	switch (ftype)
	{
	case PRES_F:
		return new PresidentialPardonForm(target);
		break;
	case ROB_F:
		return new RobotomyRequestForm(target);
		break;
	case SHRU_F:
		return new ShrubberyCreationForm(target);
		break;
	default:
		throw std::runtime_error("Useless intern. The implementation is incomplete.");
		break;
	}
}
