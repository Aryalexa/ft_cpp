#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon();
	Weapon(std::string weaponType);
	~Weapon();
	const std::string &getType() const;
	void setType(const std::string &newType);
};

#endif

