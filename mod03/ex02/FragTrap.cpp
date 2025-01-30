

#include "FragTrap.hpp"


FragTrap::FragTrap(): ClapTrap("frag-no-name", 100, 100, 30)
{
	std::cout << "FragTrap default constructor()" << std::endl;
}
FragTrap::FragTrap(const std::string name): ClapTrap(name, 100, 100, 30)
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

	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
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

const std::string FragTrap::toString() const
{
	using std::string;
	string str = "FragTrap";
	str += "[base=";
	str += ClapTrap::toString();
	str += "]";
	return str;

}
std::ostream &operator<<(std::ostream &ost, const FragTrap &x)
{
	ost << x.toString();
	return ost;
}