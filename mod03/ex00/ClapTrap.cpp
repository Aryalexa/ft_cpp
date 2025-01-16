
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("no-name"),
	hit_points(0),energy_points(0),attack_damage(0)
{
	std::cout << "ClapTrap default constructor()" << std::endl;
}
ClapTrap::ClapTrap(std::string name): name(name),
	hit_points(10),energy_points(10),attack_damage(0)
{
	std::cout << "ClapTrap constructor with args()" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other): name(other.name),
	hit_points(other.hit_points), energy_points(other.energy_points),
	attack_damage(other.attack_damage)
{
	std::cout << "ClapTrap copy constructor()" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap = operator()" << std::endl;

	if (this == &other)
		return *this;
	*this = ClapTrap(other);
	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor()" << std::endl;

}
void ClapTrap::attack(const std::string& target)
{
	int cost = 1;
	if (energy_points < cost)
	{
		std::cout << "ClapTrap " << name << " has no energy to attack." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	--energy_points;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " has taken "<< amount << " points of damage." << std::endl;
	hit_points -= amount;
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " has 0 hit points - dead!" << std::endl;
		hit_points = 0;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	int cost = 1;
	if (energy_points < cost)
	{
		std::cout << "ClapTrap " << name << " has no energy to be repaired." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " recovers " << amount << " points." << std::endl;
	hit_points += amount;
	--energy_points;
}

int ClapTrap::getAttackDamage() const
{
	return attack_damage;
}
const std::string &ClapTrap::getName() const
{
	return name;
}