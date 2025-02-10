
#include "Animal.hpp"

Animal::Animal(): type("unknown")
{
	std::cout << "Animal default constructor()" << std::endl;
}
Animal::Animal(const std::string &type): type(type)
{
	std::cout << "Animal parametrized constructor()" << std::endl;
}
Animal::Animal(const Animal &other): type(other.type)
{
	std::cout << "Animal copy constructor()" << std::endl;
}
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal = operator()" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}
Animal::~Animal()
{
	std::cout << "Animal destructor()" << std::endl;
}

const std::string &Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes sound." << std::endl;
}
