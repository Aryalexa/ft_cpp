
#include "Dog.hpp"


Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog default constructor()" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other.type)
{
	std::cout << "Dog copy constructor()" << std::endl;
}
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog = operator()" << std::endl;
	if (this == &other)
		return *this;
	*this = Dog(other);
	return *this;
}
Dog::~Dog()
{
	std::cout << "Dog destructor()" << std::endl;
}
void Dog::makeSound() const
{
	std::cout << "Dog barks." << std::endl;
}