#pragma once

#include <string>
#include <iostream>
#include <sstream>


class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const std::string &type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	const std::string &getType() const;
	virtual void makeSound() const;

	virtual const std::string toString() const;

};

std::ostream &operator<<(std::ostream &ost, const Animal &x);