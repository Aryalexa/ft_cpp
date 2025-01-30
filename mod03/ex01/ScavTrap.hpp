#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
	/* data */
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &other);
	
	void attack(const std::string& target);
	void guardGate();

	const std::string toString() const;

};

std::ostream &operator<<(std::ostream &ost, const ScavTrap &x);