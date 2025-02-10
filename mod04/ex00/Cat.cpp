#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat default constructor()" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other.type)
{
	std::cout << "Cat copy constructor()" << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat = operator()" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}
Cat::~Cat()
{
	std::cout << "Cat destructor()" << std::endl;
}
void Cat::makeSound() const
{
	std::cout << "Cat meows!" << std::endl;
}
