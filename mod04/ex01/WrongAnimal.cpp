
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("unknown")
{
	std::cout << "WrongAnimal default constructor()" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string &type): type(type)
{
	std::cout << "WrongAnimal parametrized constructor()" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other): type(other.type)
{
	std::cout << "WrongAnimal copy constructor()" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal = operator()" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor()" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes sound." << std::endl;
}
