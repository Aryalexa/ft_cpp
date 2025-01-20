
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << CYAN "Ice default constructor()" RESET << std::endl;
}
Ice::Ice(const Ice &other): AMateria(other.AMateria::type)
{
	std::cout << CYAN "Ice copy constructor()" RESET << std::endl;
}
Ice &Ice::operator=(const Ice &other)
{
	std::cout << CYAN "Ice = operator()" RESET << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}
Ice::~Ice()
{
	std::cout << MAGENTA "Ice destructor()" RESET << std::endl;
}
AMateria* Ice::clone() const
{
	return new Ice();
}
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
