
#include "AMateria.hpp"

AMateria::AMateria(): type("unknown")
{
	std::cout << CYAN "AMateria default constructor()" RESET << std::endl;
}
AMateria::AMateria(std::string const & type): type(type)
{
	std::cout << CYAN "AMateria parametrized constructor()" RESET << std::endl;
}
AMateria::AMateria(const AMateria &other): type(other.type)
{
	std::cout << CYAN "AMateria copy constructor()" RESET << std::endl;
}
AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << CYAN "AMateria operator=()" RESET << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}
AMateria::~AMateria()
{
	std::cout << MAGENTA "AMateria destructor()" RESET << std::endl;
}
std::string const & AMateria::getType() const
{
	return type;
}
void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << type << " is used against " << target.getName() << std::endl;
}