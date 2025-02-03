
#include "Dog.hpp"


Dog::Dog(): Animal("Dog"), brain(new Brain)
{
	std::cout << "Dog default constructor()" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other.type)
{
	std::cout << "Dog copy constructor()" << std::endl;
	brain = new Brain;
	*brain = *other.brain;
}
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog = operator()" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}
Dog::~Dog()
{
	std::cout << "Dog destructor()" << std::endl;
	delete brain;
}
void Dog::makeSound() const
{
	std::cout << "Dog barks." << std::endl;
}
void Dog::haveAnIdea(const std::string &idea)
{
	brain->addIdea(idea);
}
void Dog::showIdeas() const
{
	brain->showIdeas();
}