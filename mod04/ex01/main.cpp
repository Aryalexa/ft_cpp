#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "Test 🌼1" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j; //should not create a leak
		delete i;
	}
	{
		std::cout << "Test 🌼2" << std::endl;
		const int N = 10;
		// array of animal pointers
		Animal* arr[N];
		for (int i = 0; i < N; i+=2)
		{
			std::cout << i << std::endl;
			arr[i] = new Cat();
			arr[i+1] = new Dog();
		}
		for (int i = 0; i < N; ++i)
		{
			std::cout << i << std::endl;
			delete arr[i];
		}
	}
	{
		std::cout << "Test 🌼3" << std::endl;
		// check deep copies
		Cat a;
		a.haveAnIdea("fish");
		a.haveAnIdea("more fish");
		a.haveAnIdea("mice");
		Cat b = a;
		Cat c;
		c = b;
		std::cout << "BEFORE" << std::endl;
		a.showIdeas();
		b.showIdeas();
		c.showIdeas();
		c.haveAnIdea("purr");
		b.haveAnIdea("food");
		a.haveAnIdea("go out");
		std::cout << "AFTER" << std::endl;
		a.showIdeas();
		b.showIdeas();
		c.showIdeas();
	}
	{
		std::cout << "Test 🌼4" << std::endl;
		// check deep copies
		Dog a;
		a.haveAnIdea("water");
		a.haveAnIdea("ball");
		Dog b(a);
		std::cout << "BEFORE" << std::endl;
		a.showIdeas();
		b.showIdeas();
		a.haveAnIdea("go out");
		b.haveAnIdea("food");
		std::cout << "AFTER" << std::endl;
		a.showIdeas();
		b.showIdeas();
	}
	return 0;
}