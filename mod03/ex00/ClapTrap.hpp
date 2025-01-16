
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
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	int getAttackDamage() const;
	const std::string &getName() const;


};
