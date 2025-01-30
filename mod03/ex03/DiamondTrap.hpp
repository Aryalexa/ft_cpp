#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &other);

	void attack(const std::string& target);
	void whoAmI();

	const std::string toString() const;

};

std::ostream &operator<<(std::ostream &ost, const DiamondTrap &x);