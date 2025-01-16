
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap cp_a("AA");
	ClapTrap cp_b("BB");
	ScavTrap robot_c("SS");
	FragTrap robot_d("TT");

	robot_d.attack(robot_c.getName());
	robot_c.takeDamage(robot_d.getAttackDamage());
	
	robot_c.beRepaired(3);
	robot_d.beRepaired(3);
	robot_c.guardGate();
	robot_d.highFivesGuys();
}