#include "Zombie.hpp"

Zombie::Zombie() : name("no-name")
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " died." << std::endl;
}

void Zombie::setName(std::string new_name) {
	name = new_name;
}
void Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
