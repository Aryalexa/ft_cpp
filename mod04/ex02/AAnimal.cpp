
#include "AAnimal.hpp"

AAnimal::AAnimal(): type("unknown")
{
	std::cout << "AAnimal default constructor()" << std::endl;
}
AAnimal::AAnimal(const std::string &type): type(type)
{
	std::cout << "AAnimal parametrized constructor()" << std::endl;
}
AAnimal::AAnimal(const AAnimal &other): type(other.type)
{
	std::cout << "AAnimal copy constructor()" << std::endl;
}
AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal = operator()" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor()" << std::endl;
}

const std::string &AAnimal::getType() const
{
	return type;
}

