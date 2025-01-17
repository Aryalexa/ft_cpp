
#include "ClapTrap.hpp"

int main()
{
	ClapTrap cp_a("AA");
	ClapTrap cp_b("BB");
	for (int i=0;i<11;++i)
	{
		cp_a.attack(cp_b.getName());
		cp_b.takeDamage(cp_a.getAttackDamage());
	}
	cp_b.beRepaired(3);
	cp_a.beRepaired(3);
	cp_a.attack(cp_b.getName());
	cp_b.takeDamage(cp_a.getAttackDamage());
}