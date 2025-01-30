
#include "DiamondTrap.hpp"

int main()
{
	{
		DiamondTrap dia_e("EE");
		DiamondTrap dia_e1;
		dia_e1 = dia_e;
		std::cout << "copy" << std::endl;
		DiamondTrap dia_e2 = dia_e;
		std::cout << "print" << std::endl;
		std::cout << dia_e << std::endl;
		std::cout << dia_e1 << std::endl;
		std::cout << dia_e2 << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;

	DiamondTrap dc("CC");
	DiamondTrap dd("DD");

	std::cout << dc << std::endl;
	std::cout << dd << std::endl;

	dd.attack(dc.getName());
	dc.takeDamage(dd.getAttackDamage());
	std::cout << dc << std::endl;
	std::cout << dd << std::endl;
	
	dc.beRepaired(3);
	dd.beRepaired(3);
	std::cout << dc << std::endl;
	std::cout << dd << std::endl;
	dc.guardGate();
	dd.highFivesGuys();
	dc.whoAmI();
	dd.whoAmI();

}