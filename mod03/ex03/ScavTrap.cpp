

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(): ClapTrap("scav-no-name", HITPOINTS, ENERGYPOINTS, ATTACKDAMAGE)
{
	std::cout << "ScavTrap default constructor()" << std::endl;
}
ScavTrap::ScavTrap(const std::string &name): ClapTrap(name, HITPOINTS, ENERGYPOINTS, ATTACKDAMAGE)
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

	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor()" << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
	int energy_cost = 1;
	if (hit_points <= 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack. It's dead." << std::endl;
		return;
	}
	if (energy_points < energy_cost)
	{
		std::cout << "ScavTrap " << name << " has no energy to attack." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points -= energy_cost;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap "<< name<< " is now in Gate keeper mode." << std::endl;
}

const std::string ScavTrap::toString() const
{
	using std::string;
	string str = "ScavTrap";
	str += "[base=";
	str += ClapTrap::toString();
	str += "]";
	return str;

}
std::ostream &operator<<(std::ostream &ost, const ScavTrap &x)
{
	ost << x.toString();
	return ost;
}