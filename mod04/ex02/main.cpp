#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		std::cout << "Test 🌼1" << std::endl;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j; //should not create a leak
		delete i;
	}
	{
		std::cout << "Test 🌼2" << std::endl;
		const AAnimal* j = new Dog(); // pointer
		const AAnimal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		delete j;
		delete i;
	}
	{
		std::cout << "Test 🌼3" << std::endl;
		Dog dog;
		Cat cat;
		AAnimal& ref1 = dog; // reference
		AAnimal& ref2 = cat;
		std::cout << dog.getType() << " " << std::endl;
		std::cout << cat.getType() << " " << std::endl;
		ref1.makeSound(); // will output the dog sound!
		ref2.makeSound();
	}
	{
		std::cout << "Test 🌼4" << std::endl;
		Dog a;
		a.haveAnIdea("water");
		a.haveAnIdea("ball");
		a.showIdeas();
	}
	return 0;
}