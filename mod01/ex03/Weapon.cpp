#include "Weapon.hpp"


Weapon::Weapon()
{
}
Weapon::Weapon(std::string weaponType): type(weaponType)
{
}
Weapon::~Weapon()
{
}
/**
 * Getter
 * first const: the returned variable cannot be modified
 * second const: the object that calls this function can be a const, 
 *   and its guaranteed that the function cannot modify the object calling.
 */
const std::string &Weapon::getType() const {
	return type;
}
void Weapon::setType(const std::string &newType) {
	type = newType;
}