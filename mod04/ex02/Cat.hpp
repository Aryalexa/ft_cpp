
#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();
	void makeSound() const;
	void haveAnIdea(const std::string &idea);
	void showIdeas() const;
};
