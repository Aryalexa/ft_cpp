
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap cp_a("AA");
	ClapTrap cp_b("BB");
	ScavTrap robot_c("SS");

	robot_c.attack(cp_b.getName());
	cp_b.takeDamage(robot_c.getAttackDamage());
	
	cp_b.beRepaired(3);
	robot_c.beRepaired(3);
	robot_c.guardGate();
}