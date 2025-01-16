

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(): ClapTrap("scav-no-name")
{
	std::cout << "ScavTrap default constructor()" << std::endl;
}
ScavTrap::ScavTrap(const std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor with args()" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor()" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap = operator()" << std::endl;

	if (this == &other)
		return *this;
	*this = ScavTrap(other);
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor()" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap "<< name<< " is now in Gate keeper mode." << std::endl;
}
