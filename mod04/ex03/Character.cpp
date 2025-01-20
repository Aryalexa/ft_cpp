
#include "Character.hpp"

Character::Character(): name("unknown"), inv_occ(0)
{
	std::cout << CYAN "Character default constructor()" RESET << std::endl;

}
Character::Character(const std::string &name): name(name), inv_occ(0) 
{
	std::cout << CYAN "Character paremetrized constructor()" RESET << std::endl;
}

Character::Character(const Character &other): name(other.name), inv_occ(other.inv_occ)
{
	std::cout << CYAN "Character copy constructor()" RESET << std::endl;
	for (int i = 0; i < other.inv_occ; ++i)
		inventory[i] = other.inventory[i]->clone();
}
Character &Character::operator=(const Character &other)
{
	std::cout << CYAN "Character = operator()" RESET << std::endl;
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < inv_occ; ++i)
			delete inventory[i];
		inv_occ = other.inv_occ;
		for (int i = 0; i < other.inv_occ; ++i)
			inventory[i] = other.inventory[i]->clone();
	}
	return *this;
}
Character::~Character()
{
	std::cout << MAGENTA "Character destructor()" RESET << std::endl;
	for (int i = 0; i < inv_occ; ++i)
		delete inventory[i];
}
std::string const &Character::getName() const
{
	return name;
}
void Character::setName(const std::string &newName)
{
	name = newName;
}

/** only saves the pointer, no clone */
void Character::equip(AMateria* m)
{
	if (m == NULL)
	std::cout << "Character " << name << " cannot equip inexisting materia." << std::endl;
	if (inv_occ == INV_CAP)
	{
		std::cout << "Character " << name << " cannot carry anymore material." << std::endl;
		return;
	}
	inventory[inv_occ++] = m;
	std::cout << "Character " << name << " now has " << m->getType() << std::endl;
}
// must NOT delete the Materia!
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= inv_occ)
		return;
	std::cout << "Character " << name << " leaves " << inventory[idx]->getType() << " on the floor. "<< std::endl;
	for (int i = idx; i < inv_occ - 1; ++i)
	{
		inventory[i] = inventory[i+1];
	}
	--inv_occ;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= inv_occ)
		return;
	std::cout << "Character " << name << " uses " << inventory[idx]->getType() 
		<< " on " << target.getName() << std::endl;
	inventory[idx]->use(target);
}

void Character::showInventory() const
{
	std::cout << "Character " << name << "'s inventory:"<< std::endl;
	for (int i = 0; i < inv_occ; ++i)
		std::cout << "  " << i << " " << inventory[i]->getType() << std::endl;

	if (inv_occ == 0)
		std::cout << " nothing" << std::endl;
	
	
}
