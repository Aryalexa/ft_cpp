
#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor()" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other.type)
{
	std::cout << "WrongCat copy constructor()" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat = operator()" << std::endl;
	if (this == &other)
		return *this;
	*this = WrongCat(other);
	return *this;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor()" << std::endl;
}
void WrongCat::makeSound() const
{
	std::cout << "WrongCat says: djfjdndjncsh." << std::endl;
}