
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap cp_a("AA");
	DiamondTrap cp_b("BB");
	DiamondTrap robot_c("SS");
	DiamondTrap robot_d("TT");
	std::cout << cp_a << std::endl;
	std::cout << cp_b << std::endl;
	std::cout << robot_c << std::endl;
	std::cout << robot_d << std::endl;

	robot_d.attack(robot_c.getName());
	robot_c.takeDamage(robot_d.getAttackDamage());
	std::cout << robot_c << std::endl;
	std::cout << robot_d << std::endl;
	
	robot_c.beRepaired(3);
	robot_d.beRepaired(3);
	std::cout << robot_c << std::endl;
	std::cout << robot_d << std::endl;
	robot_c.guardGate();
	robot_d.highFivesGuys();
	cp_a.whoAmI();
	cp_b.whoAmI();
	robot_c.whoAmI();
	robot_d.whoAmI();
}