
#pragma once

#include <string>
#include <iostream>

//#include "AMateria.hpp" -> forawrd definition - enough to use pointers and refs
class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
	virtual void showInventory() const = 0;
};
