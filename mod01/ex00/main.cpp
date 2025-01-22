#include "Zombie.hpp"

int main ()
{
	Zombie *w = new Zombie("aa");
	w->announce();
	delete w;

	Zombie *z;
	z = new Zombie("sdf");
	z->announce();
	delete z;
	
	z = newZombie("hippieZombie456");
	z->announce();
	delete z;

	randomChump("Z_34LOC");

	return 0;
}