
#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
private:
	/* data */
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();
	void makeSound() const;

	const std::string toString() const;

};

std::ostream &operator<<(std::ostream &ost, const Animal &x);
