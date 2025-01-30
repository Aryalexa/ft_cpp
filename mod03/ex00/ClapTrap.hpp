
#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string name;
	int hit_points; // health
	int energy_points;
	int attack_damage;

public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
	const std::string &getName() const;

};

std::ostream &operator<<(std::ostream &ost, const ClapTrap &x);