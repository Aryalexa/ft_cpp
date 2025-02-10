#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	using std::cout;
	using std::endl;
	{
		cout << "🌼Test 1 - pointers, leaks" << endl;
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		delete dog; //should not create a leak
		delete cat;
	}
	{
		cout << "🌼Test 2 - array of animals" << endl;
		const int N = 10;
		// array of animal pointers
		Animal* arr[N];
		for (int i = 0; i < N; i+=2)
		{
			cout << i << endl;
			arr[i] = new Cat();
			arr[i+1] = new Dog();
		}
		for (int i = 0; i < N; ++i)
			arr[i]->makeSound();
		for (int i = 0; i < N; ++i)
		{
			cout << i << endl;
			delete arr[i];
		}
	}
	{
		cout << "🌼Test 3 - deep copy (cat)" << endl;
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
	{
		cout << "🌼Test 4 - deep copy (dog)" << endl;

		Dog a;
		a.haveAnIdea("water");
		a.haveAnIdea("ball");
		Dog b(a);
		cout << "BEFORE" << endl;
		a.showIdeas();
		b.showIdeas();
		a.haveAnIdea("go out");
		b.haveAnIdea("food");
		cout << "AFTER" << endl;
		a.showIdeas();
		b.showIdeas();
	}
	return 0;
}