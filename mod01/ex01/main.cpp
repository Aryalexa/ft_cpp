#include "Zombie.hpp"

int main ()
{
	Zombie *zs;
	int N = 5;
	zs = zombieHorde(N, "hippieZombie33");
	
	for (int i = 0; i < N; ++i)
		zs[i].announce();
	
	delete [] zs;

	return 0;
}