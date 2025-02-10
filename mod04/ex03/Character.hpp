#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Colors.h"

class Character : public ICharacter
{
private:
	std::string name;

	static const int INV_MAX = 4;
	AMateria* inventory[INV_MAX];
	int inv_cnt;
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
