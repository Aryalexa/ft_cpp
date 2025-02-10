
#include "Character.hpp"

Character::Character(): name("unknown"), inv_cnt(0)
{
	std::cout << CYAN "🏃Character default constructor()" RESET << std::endl;

}
Character::Character(const std::string &name): name(name), inv_cnt(0) 
{
	std::cout << CYAN "🏃Character paremetrized constructor()" RESET << std::endl;
}

Character::Character(const Character &other): name(other.name), inv_cnt(other.inv_cnt)
{
	std::cout << CYAN "🏃Character copy constructor()" RESET << std::endl;
	for (int i = 0; i < other.inv_cnt; ++i)
		inventory[i] = other.inventory[i]->clone();
}
Character &Character::operator=(const Character &other)
{
	std::cout << CYAN "🏃Character operator=()" RESET << std::endl;
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < inv_cnt; ++i)
			delete inventory[i];
		inv_cnt = other.inv_cnt;
		for (int i = 0; i < other.inv_cnt; ++i)
			inventory[i] = other.inventory[i]->clone();
	}
	return *this;
}
Character::~Character()
{
	std::cout << MAGENTA "🏃Character destructor()" RESET << std::endl;
	for (int i = 0; i < inv_cnt; ++i)
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
		return;
	if (inv_cnt == INV_MAX)
	{
		std::cout << "🏃Character " << name << " cannot carry anymore materia." << std::endl;
		return;
	}
	inventory[inv_cnt++] = m;
	std::cout << "🏃Character " << name << " now has " << m->getType() << std::endl;
}
// must NOT delete the Materia!
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= inv_cnt)
		return;
	std::cout << "🏃Character " << name << " leaves " << inventory[idx]->getType() << " on the floor." << std::endl;
	for (int i = idx; i < inv_cnt - 1; ++i)
	{
		inventory[i] = inventory[i + 1];
	}
	--inv_cnt;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= inv_cnt)
		return;
	std::cout << "🏃Character " << name << " uses " << inventory[idx]->getType() 
		<< " on " << target.getName() << std::endl;
	inventory[idx]->use(target);
}

void Character::showInventory() const
{
	std::cout << "🏃Character " << name << "'s inventory:"<< std::endl;
	for (int i = 0; i < inv_cnt; ++i)
		std::cout << "  " << i << " " << inventory[i]->getType() << std::endl;

	if (inv_cnt == 0)
		std::cout << " nothing" << std::endl;
	
	
}
