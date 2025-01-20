#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		Animal a;
		a = Animal("other");
	}
	std::cout << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog(); // pointer
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); // will output the cat sound!
	meta->makeSound();	
	delete meta;
	delete j;
	delete i;
	if (1)
	{
		std::cout << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog(); // pointer
		const WrongAnimal* i = new WrongCat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound(); // will output the cat sound!
		meta->makeSound();	
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		Dog dog;
		Cat cat;
		Animal& ref1 = dog; // reference
		Animal& ref2 = cat;
		std::cout << dog.getType() << " " << std::endl;
		std::cout << cat.getType() << " " << std::endl;
		ref1.makeSound(); // will output the dog sound!
		ref2.makeSound();
	}
	std::cout << std::endl;
	Animal animal;
	std::cout << animal.getType() << " " << std::endl;
	animal.makeSound();
	
	return 0;
}