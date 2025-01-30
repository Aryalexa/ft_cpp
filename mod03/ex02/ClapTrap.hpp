
#pragma once

#include <string>
#include <iostream>
#include <sstream>


class ClapTrap
{
protected:
	std::string name;
	int hit_points; // health
	int energy_points;
	int attack_damage;

public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const std::string &name, int hit_points, int energy_points, int attack_damage);
	ClapTrap(const ClapTrap &other);
	virtual ~ClapTrap();

	ClapTrap &operator=(const ClapTrap &other);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
	const std::string &getName() const;

	virtual const std::string toString() const;

};

std::ostream &operator<<(std::ostream &ost, const ClapTrap &x);