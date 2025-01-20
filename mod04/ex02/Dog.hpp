
#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();
	void makeSound() const;
	void haveAnIdea(const std::string &idea);
	void showIdeas() const;
};
