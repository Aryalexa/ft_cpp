
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("no-name"),
	hit_points(10),energy_points(10),attack_damage(0)
{
	std::cout << "ClapTrap default constructor()" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name): name(name),
	hit_points(10),energy_points(10),attack_damage(0)
{
	std::cout << "ClapTrap constructor with args()" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name, int hit_points, int energy_points, int attack_damage):
	name(name),
	hit_points(hit_points),
	energy_points(energy_points),
	attack_damage(attack_damage)
{
	std::cout << "ClapTrap constructor with all args()" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other):
	name(other.name),
	hit_points(other.hit_points), 
	energy_points(other.energy_points),
	attack_damage(other.attack_damage)
{
	std::cout << "ClapTrap copy constructor()" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap = operator()" << std::endl;

	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor()" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	int energy_cost = 1;
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack. It's dead." << std::endl;
		return;
	}
	if (energy_points < energy_cost)
	{
		std::cout << "ClapTrap " << name << " has no energy to attack." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points -= energy_cost;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot take more damage. It's already dead." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " has taken "<< amount << " points of damage." << std::endl;
	hit_points -= amount;
	if (hit_points < 0)
		hit_points = 0;

	if (hit_points == 0)
		std::cout << "ClapTrap " << name << " has 0 hit points - dead!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	int energy_cost = 1;
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot repair itself. It's dead." << std::endl;
		return;
	}
	if (energy_points < energy_cost)
	{
		std::cout << "ClapTrap " << name << " has no energy to be repaired." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " recovers " << amount << " points." << std::endl;
	hit_points += amount;
	energy_points -= energy_cost;
}

int ClapTrap::getHitPoints() const
{
	return hit_points;
}
int ClapTrap::getEnergyPoints() const
{
	return energy_points;
}
int ClapTrap::getAttackDamage() const
{
	return attack_damage;
}
const std::string &ClapTrap::getName() const
{
	return name;
}
const std::string ClapTrap::toString() const
{
	std::ostringstream ss;

	ss << "ClapTrap";
	ss << "(name=";
	ss << name;
	ss << ",hit_points=";
	ss << (hit_points);
	ss << ",energy_points=";
	ss << energy_points;
	ss << ",attack_damage=";
	ss << attack_damage;
	ss << ")";
	return ss.str();

}

std::ostream &operator<<(std::ostream &ost, const ClapTrap &x)
{
	ost << x.toString();
return ost;
}