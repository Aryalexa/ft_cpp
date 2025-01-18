

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

	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor()" << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
	int cost = 1;
	if (energy_points < cost)
	{
		std::cout << "ScavTrap " << name << " has no energy to attack." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	--energy_points;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap "<< name<< " is now in Gate keeper mode." << std::endl;
}
