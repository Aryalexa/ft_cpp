#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Colors.h"

class Character : public ICharacter
{
private:
	static const int INV_CAP = 4;
	std::string name;
	AMateria* inventory[INV_CAP];
	int inv_occ;
public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();
	std::string const & getName() const;
	void setName(const std::string &name);
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void showInventory() const;

};
