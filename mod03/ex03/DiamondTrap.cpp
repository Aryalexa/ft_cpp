
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("dia-no-name")
{
	std::cout << "DiamondTrap default constructor()" << std::endl;
}
DiamondTrap::DiamondTrap(const std::string name): 
	ClapTrap(name+"_clap_name", FragTrap::HITPOINTS, ScavTrap::ENERGYPOINTS, FragTrap::ATTACKDAMAGE),
	name(name)
{
	std::cout << "DiamondTrap constructor with args()" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other)
{
	std::cout << "DiamondTrap copy constructor()" << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap = operator()" << std::endl;

	if (this == &other)
		return *this;
	*this = DiamondTrap(other);
	return *this;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor()" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	std::cout << "DiamondTrap " << name << " tries to atttack " << target << std::endl;
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap identifing itself. It's " << name << " aka " << ClapTrap::name << std::endl;
}

std::ostream &operator<<(std::ostream &ost, const DiamondTrap &x)
{
	ost << "DiamondTrap[" << (ClapTrap)x << "]";
	return ost;
}