#pragma once

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
protected:
	static const int HITPOINTS = 100;
	static const int ENERGYPOINTS = 50;
	static const int ATTACKDAMAGE = 20;
public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();
	void guardGate();

};
std::ostream &operator<<(std::ostream &ost, const ScavTrap &x);