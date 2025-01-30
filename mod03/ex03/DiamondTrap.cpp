
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():
	ClapTrap("noname_clap_name", FragTrap::HITPOINTS, ScavTrap::ENERGYPOINTS, FragTrap::ATTACKDAMAGE),
	// ScavTrap(),
	// FragTrap(),
	name("noname")
{
	std::cout << "DiamondTrap default constructor()" << std::endl;
}
DiamondTrap::DiamondTrap(const std::string name): 
	ClapTrap(name+"_clap_name", FragTrap::HITPOINTS, ScavTrap::ENERGYPOINTS, FragTrap::ATTACKDAMAGE),
	// ScavTrap(),
	// FragTrap(),
	name(name)
{
	std::cout << "DiamondTrap constructor with args()" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other):
	ClapTrap(other),
	// ScavTrap(),
	// FragTrap(),
	name(other.name)
{
	std::cout << "DiamondTrap copy constructor()" << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap = operator()" << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor()" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	std::cout << "DiamondTrap " << name << " tries to attack " << target << std::endl;
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap identifing itself. It's " << name << " aka " << ClapTrap::name << std::endl;
}

const std::string DiamondTrap::toString() const
{
	using std::string;
	string str = "FragTrap";
	str += "[name=";
	str += name;
	str += ",\n\tClapTrapBASE=";
	str += ClapTrap::toString();
	// str += ",\n\tScavTrap=";
	// str += ScavTrap::toString();
	// str += ",\n\tFragTrap=";
	// str += FragTrap::toString();
	str += "]";
	return str;

}
std::ostream &operator<<(std::ostream &ost, const DiamondTrap &x)
{
	ost << x.toString();
	return ost;
}