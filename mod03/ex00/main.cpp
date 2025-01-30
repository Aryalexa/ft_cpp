
#include "ClapTrap.hpp"

int main()
{
	using std::cout;
	using std::endl;
	{
		cout << "🌼 TEST 1" << endl;

		ClapTrap cp_a("AA");
		ClapTrap cp_b("BB");
		ClapTrap cp_c("CC");

		cout << "a: " << cp_a << endl;
		cout << "b: " << cp_b << endl;
		cout << "c: " << cp_c << endl;

		cp_a.attack(cp_b.getName());
		cp_b.takeDamage(cp_a.getAttackDamage());

		cout << cp_a << endl;
		cout << cp_b << endl;

		cout << "copies" << endl;
		ClapTrap cp_a2 = cp_a;
		cp_c = cp_a;
		cout << cp_a << endl;
		cout << cp_b << endl;
		cout << cp_c << endl;
		cout << cp_a2 << endl;

		cp_c.beRepaired(2);
		cout << cp_a << endl;
		cout << cp_b << endl;
		cout << cp_c << endl;
		cout << cp_a2 << endl;
	}
	{
		cout << "🌼 TEST 2" << endl;

		ClapTrap cp_c("CC");
		ClapTrap cp_d("DD");

		cout << cp_c << endl;
		cout << cp_d << endl;

		cout << "\td vs c" << endl;
		cp_d.attack(cp_c.getName());
		cp_c.takeDamage(cp_d.getAttackDamage());
		cout << cp_c << endl;
		cout << cp_d << endl;


		cout << "\td vs d" << endl;
		cp_d.attack(cp_d.getName());
		cp_d.takeDamage(cp_d.getAttackDamage());
		cout << cp_d << endl;

	}
	{
		cout << "🌼 TEST 3" << endl;
		ClapTrap cp_a("AA");
		ClapTrap cp_b("BB");

		cout << cp_a << endl;
		cout << cp_b << endl;

		
		cout << "\ta vs b" << endl;
		for (int i = 0; i < 10; ++i)
		{
			cout << i + 1 << endl;
			cp_a.attack(cp_b.getName());
			cp_b.takeDamage(cp_a.getAttackDamage());
		}
		cout << 11 << endl;
		cp_a.attack(cp_b.getName());

		cout << cp_a << endl;
		cout << cp_b << endl;

		cp_b.beRepaired(3);
		cp_a.beRepaired(3);
		cp_a.attack(cp_b.getName());

		cout << cp_a << endl;
		cout << cp_b << endl;
	}

}