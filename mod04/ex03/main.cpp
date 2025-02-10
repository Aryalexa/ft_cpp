
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Colors.h"

void testSource()
{
	/**
	 * learn, create
	 */
	IMateriaSource* src = new MateriaSource();
	src->showLearnt();
	
	AMateria *originalIce = new Ice();
	AMateria *originalCure = new Cure();

	src->learnMateria(originalIce);
	src->learnMateria(originalCure);
	src->showLearnt();
	
	delete originalIce;
	delete originalCure;

	std::cout << "create..." << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	AMateria* tmp2;
	tmp2 = src->createMateria("cure");
	delete tmp;
	delete tmp2;

	delete src;
	
}

void testChars()
{
	/**
	 * equip, unequip, use
	 */
	ICharacter* em = new Character("EMILY");
	ICharacter* bob = new Character("BOB");

	AMateria *m0 = new Ice();
	AMateria *m1 = new Ice();
	AMateria *m2 = new Cure();

	AMateria *floor_objs[100];
	int objs = 0;

	em->equip(m0);
	em->showInventory();
	em->use(0, *bob);

	em->equip(m1);
	em->equip(m2);
	em->showInventory();

	em->unequip(1);
	floor_objs[objs++] = m1; // you cannot pick them up again!
	em->showInventory();

	em->use(1, *bob);

	delete bob;
	delete em;
	std::cout << "---" << std::endl;
	for (int i = 0; i < objs; ++i)
	{
		delete floor_objs[i];
	}


}
void testCharsCopy()
{
	/**
	 * coping chars
	 */
	Character* sally = new Character("SALLY");

	AMateria *m0 = new Ice();
	AMateria *m1 = new Ice();
	AMateria *m2 = new Ice();
	AMateria *m3 = new Cure();
	AMateria *m4 = new Cure();
	AMateria *m5 = new Cure();

	// AMateria *floor_objs[100];
	// int objs = 0;

	sally->equip(m0);
	sally->equip(m3);
	sally->showInventory();
	
	Character *gary = new Character(*sally); // gary is a copy of me
	gary->setName("GARY");
	gary->showInventory();
	gary->equip(m1);
	gary->equip(m2);
	gary->showInventory();

	sally->equip(m4);
	sally->equip(m5);
	sally->showInventory();
	
	delete sally;
	delete gary;
}

void fixed_example()
{
	IMateriaSource* src = new MateriaSource();
	//src->learnMateria(new Ice());
	Ice *ice = new Ice();
	src->learnMateria(ice);
	delete ice;
	//
	//src->learnMateria(new Cure());
	AMateria *cure = new Cure();
	src->learnMateria(cure);
	delete cure;
	//

	std::cout << "--- create Billy and equip him" << std::endl;
	ICharacter* bill = new Character("BILLY");

	// the reference is lost so we better do not unequip! (the tmp)
	AMateria* tmp;
	tmp = src->createMateria("ice");
	bill->equip(tmp);
	tmp = src->createMateria("cure");
	bill->equip(tmp);

	std::cout << "--- Bobby" << std::endl;
	ICharacter* bob = new Character("BOBBY");
	bill->use(0, *bob);
	bill->use(1, *bob);
	delete bob;
	delete bill;
	delete src;
}
int main()
{
	using std::cout;
	using std::endl;

	
	cout << endl << "TEST: source 🍁" << endl;
	testSource();

	cout << endl << "TEST: chars 🍁" << endl;
	testChars();

	cout << endl << "TEST: chars deep copy 🍁" << endl;
	testCharsCopy();

	cout << endl << "TEST: example 🍁" << endl;
	fixed_example();

	return 0;
}