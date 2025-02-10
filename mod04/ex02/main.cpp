#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	using std::cout;
	using std::endl;
	// {
	// 	AAnimal a = AAnimal(); // not possible
	// }
	{
		cout << "🍁Test 1" << endl;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j; //should not create a leak
		delete i;
	}
	{
		cout << "🍁Test 2 - pointers" << endl;
		const AAnimal* j = new Dog(); // pointer
		const AAnimal* i = new Cat();
		cout << j->getType() << " " << endl;
		cout << i->getType() << " " << endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		delete j;
		delete i;
	}
	{
		cout << "🍁Test 3 - refs" << endl;
		Dog dog;
		Cat cat;
		AAnimal& ref1 = dog; // reference
		AAnimal& ref2 = cat;
		cout << dog.getType() << " " << endl;
		cout << cat.getType() << " " << endl;
		ref1.makeSound(); // will output the dog sound!
		ref2.makeSound();
	}
	{
		cout << "🍁Test 4 - ideas" << endl;
		Dog a;
		a.haveAnIdea("water");
		a.haveAnIdea("ball");
		a.showIdeas();
	}
	{
		cout << "🍁Test 5 - deep copy (cat)" << endl;
		// check deep copies
		Cat a;
		a.haveAnIdea("fish");
		a.haveAnIdea("more fish");
		a.haveAnIdea("mice");
		Cat b = a;
		Cat c;
		c = b;
		cout << "BEFORE" << endl;
		a.showIdeas();
		b.showIdeas();
		c.showIdeas();
		c.haveAnIdea("purr");
		b.haveAnIdea("food");
		a.haveAnIdea("go out");
		cout << "AFTER" << endl;
		a.showIdeas();
		b.showIdeas();
		c.showIdeas();
	}
	return 0;
}