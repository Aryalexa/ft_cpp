#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat"), brain(new Brain)
{
	std::cout << "Cat default constructor()🐈" << std::endl;
}

Cat::Cat(const Cat &other): AAnimal(other.type)
{
	std::cout << "Cat copy constructor()🐈" << std::endl;
	brain = new Brain(*other.brain);
}
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat = operator()🐈" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}
Cat::~Cat()
{
	std::cout << "Cat destructor()🐈" << std::endl;
	delete brain;
}
void Cat::makeSound() const
{
	std::cout << "Cat meows!🐈" << std::endl;
}
void Cat::haveAnIdea(const std::string &idea)
{
	brain->addIdea(idea);
}
void Cat::showIdeas() const
{
	brain->showIdeas();
}

