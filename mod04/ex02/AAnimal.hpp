#pragma once

#include <string>
#include <iostream>

class AAnimal
{
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const std::string &type);
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();

	const std::string &getType() const;
	virtual void makeSound() const = 0;
};
