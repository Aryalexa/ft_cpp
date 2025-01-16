

#include "FragTrap.hpp"


FragTrap::FragTrap(): ClapTrap("frag-no-name")
{
	std::cout << "FragTrap default constructor()" << std::endl;
}
FragTrap::FragTrap(const std::string name): ClapTrap(name, HITPOINTS, ENERGYPOINTS, ATTACKDAMAGE)
{
	std::cout << "FragTrap constructor with args()" << std::endl;
}
FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "FragTrap copy constructor()" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap = operator()" << std::endl;

	if (this == &other)
		return *this;
	*this = FragTrap(other);
	return *this;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor()" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << ": Gimme five!" << std::endl;
}
std::ostream &operator<<(std::ostream &ost, const FragTrap &x)
{
	ost << "FragTrap[" << (ClapTrap)x << "]";
	return ost;
}