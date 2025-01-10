#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *zs = new Zombie[N];
	for (int i = 0; i < N; ++i)
		new (&zs[i]) Zombie(name); // placement-new initialization - the ith address
		//zs[i].setName(name);
	return zs;
}