#pragma once

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
protected:
	static const int HITPOINTS = 100;
	static const int ENERGYPOINTS = 100;
	static const int ATTACKDAMAGE = 30;

	/* data */
public:
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &other);
	~FragTrap();

	FragTrap &operator=(const FragTrap &other);
	
	void highFivesGuys(void);

	const std::string toString() const;

};

std::ostream &operator<<(std::ostream &ost, const FragTrap &x);
