#include "Zombie.hpp"

int main ()
{
	Zombie *zs;
	int N = 4;
	zs = zombieHorde(N, "hippieZombie33");
	for (int i = 0; i < N; ++i)
		zs->announce();
	delete [] zs;

	return 0;
}