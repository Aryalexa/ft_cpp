
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	using std::cout;
	using std::endl;

	{
		cout << "🌼 TEST 1" << endl;

		ScavTrap ss("SS");
		FragTrap ff("FF");

		cout << ss << endl;
		cout << ff << endl;

		ff.attack(ss.getName());
		ss.takeDamage(ff.getAttackDamage());

		cout << ss << endl;
		cout << ff << endl;
		
		ss.attack(ff.getName());
		ff.takeDamage(ss.getAttackDamage());
		
		cout << ss << endl;
		cout << ff << endl;

		ss.beRepaired(3);
		ff.beRepaired(3);

		cout << ss << endl;
		cout << ff << endl;

		ss.guardGate();
		ff.highFivesGuys();
	}
	{
		cout << "🌼 TEST 2" << endl;

		ClapTrap *x = new FragTrap("FF");
		cout << *x << endl;

		x->beRepaired(2);
		cout << *x << endl;

	}
}