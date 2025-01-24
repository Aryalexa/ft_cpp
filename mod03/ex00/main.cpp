
#include "ClapTrap.hpp"

int main()
{
	ClapTrap cp_a("AA");
	ClapTrap cp_b("BB");
	ClapTrap cp_c = cp_a;
	ClapTrap cp_d;
	cp_d = cp_b;

	std::cout << "\td vs c" << std::endl;
	cp_d.attack(cp_c.getName());
	cp_c.takeDamage(cp_d.getAttackDamage());


	std::cout << "\td vs d" << std::endl;
	cp_d.attack(cp_d.getName());
	cp_d.takeDamage(cp_d.getAttackDamage());

	std::cout << "\ta vs b" << std::endl;
	for (int i=0;i<11;++i)
	{
		cp_a.attack(cp_b.getName());
		cp_b.takeDamage(cp_a.getAttackDamage());
	}
	cp_b.beRepaired(3);
	cp_a.beRepaired(3);
	cp_a.attack(cp_b.getName());
	cp_b.takeDamage(cp_a.getAttackDamage());
	std::cout << "\tend" << std::endl;
}