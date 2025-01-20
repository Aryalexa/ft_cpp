
#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << CYAN "Cure default constructor()" RESET << std::endl;
}
Cure::Cure(const Cure &other): AMateria(other.AMateria::type)
{
	std::cout << CYAN "Cure copy constructor()" RESET << std::endl;
}
Cure &Cure::operator=(const Cure &other)
{
	std::cout << CYAN "Cure = operator()" RESET << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}
Cure::~Cure()
{
	std::cout << MAGENTA "Cure destructor()" RESET << std::endl;
}
AMateria* Cure::clone() const
{
	return new Cure();
}
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}