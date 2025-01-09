#include "Zombie.hpp"

int main ()
{
	randomChump("Z_34LOC");

	Zombie *z;
	z = newZombie("hippieZombie456");
	z->announce();
	delete z;
}