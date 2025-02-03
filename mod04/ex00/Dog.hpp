
#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
private:
	/* data */
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();
	void makeSound() const;

	const std::string toString() const;

};

std::ostream &operator<<(std::ostream &ost, const Animal &x);
