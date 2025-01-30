
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	using std::cout;
	using std::endl;
	{
		cout << "🌼 TEST 1" << endl;

		ScavTrap sa("SA");
		cout << "sa: " << sa << endl;

		sa.beRepaired(3);
		cout << "sa: " << sa << endl;


		ScavTrap sa1(sa);
		cout << "sa1: " << sa1 << endl;

		sa1.beRepaired(3);
		cout << "sa1: " << sa1 << endl;

		ScavTrap sa2;
		sa2 = sa1;
		cout << "sa2: " << sa2 << endl;

		sa2.beRepaired(3);
		cout << "sa2: " << sa2 << endl;


		cout << "final" << endl;
		cout << "sa: " << sa << endl;
		cout << "sa1: " << sa1 << endl;
		cout << "sa2: " << sa2 << endl;

	}
	{
		{
		cout << "🌼 TEST 2 - attack" << endl;

		ScavTrap ss("SS");
		ScavTrap sb("SB");
		cout << "ss: " << ss << endl;
		cout << "sb: " << sb << endl;
		
		ss.attack(sb.getName());
		sb.takeDamage(ss.getAttackDamage());
		cout << "ss: " << ss << endl;
		cout << "sb: " << sb << endl;
		
		cout << "- pointer -" << endl;
		ClapTrap *x = new ScavTrap("SX");
		cout << "pointer x: " << *x << endl;

		x->attack(sb.getName());
		sb.takeDamage(x->getAttackDamage());
		cout << "pointer x: " << *x << endl;
		cout << "sb: " << sb << endl;

		delete x;
	}
	}
	{
		cout << "🌼 TEST 3" << endl;

		ClapTrap cb("CB");
		ScavTrap ss("SS");

		cout << "ss: " << ss << endl;
		cout << "cb: " << cb << endl;

		ss.attack(cb.getName());
		cb.takeDamage(ss.getAttackDamage());

		cout << "ss: " << ss << endl;
		cout << "cb: " << cb << endl;
		
		cb.beRepaired(3);
		ss.beRepaired(3);
		ss.guardGate();

		cout << "ss: " << ss << endl;
		cout << "cb: " << cb << endl;
	}


}