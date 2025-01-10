#include "Zombie.hpp"

void randomChump( std::string name ) {
	Zombie z(name); // local variable - stack mem
	z.announce();
}

