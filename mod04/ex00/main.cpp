#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	using std::cout;
	using std::endl;
	{
		cout << "🌼 TEST 1" << endl;
		Animal a; // default
		a = Animal("fantastic animal"); // assignment
		cout << "a type: " << a.getType() << " " << endl;
		a.makeSound();

		Animal b; // default
		cout << "b type: " << b.getType() << " " << endl;
		b.makeSound();
	}
	{
		cout << "🌼 TEST 2 - pointers" << endl;
		const Animal* meta = new Animal();
		const Animal* dog = new Dog(); // pointer
		const Animal* cat = new Cat();
		cout << dog->getType() << " " << endl;
		cout << cat->getType() << " " << endl;
		dog->makeSound();
		cat->makeSound(); // will output the cat sound!
		meta->makeSound();	
		delete meta;
		delete dog;
		delete cat;
	}
	{
		cout << "🌼 TEST 3 - \"wrong\" pointers" << endl;
		const WrongAnimal* wcat = new WrongCat();
		cout << wcat->getType() << " " << endl;
		wcat->makeSound(); // will output the cat sound!
		delete wcat;
	}
	{
		cout << "🌼 TEST 4 - references" << endl;

		Dog dog;
		Cat cat;
		Animal& rdog = dog; // reference
		Animal& rcat = cat;
		cout << dog.getType() << " " << endl;
		cout << cat.getType() << " " << endl;
		rdog.makeSound(); // will output the dog sound!
		rcat.makeSound();
	}

	return 0;
}