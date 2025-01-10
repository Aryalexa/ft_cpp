#include "Zombie.hpp"

int main ()
{
	randomChump("Z_34LOC");

	Zombie *z;
	z = newZombie("hippieZombie456");
	z->announce();
	delete z;

	z = new Zombie("sdf");
	z->announce();
	delete z;

	Zombie *w = new Zombie("aa");
	w->announce();
	delete w;

	return 0;
}