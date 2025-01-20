
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
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	AMateria *m0 = new Ice();
	AMateria *m1 = new Ice();
	AMateria *m2 = new Cure();

	AMateria *floor_objs[100];
	int objs = 0;

	me->equip(m0);
	me->showInventory();
	me->use(0, *bob);

	me->equip(m1);
	me->equip(m2);
	me->showInventory();

	me->unequip(1);
	floor_objs[objs++] = m1; // you cannot pick them up again!
	me->showInventory();

	me->use(1, *bob);

	delete bob;
	delete me;
	for (int i = 0; i < objs; ++i)
	{
		delete floor_objs[i];
	}
	std::cout << " ---" << std::endl;


}
void testCharsCopy()
{
	/**
	 * coping chars
	 */
	Character* me = new Character("me");

	AMateria *m0 = new Ice();
	AMateria *m1 = new Ice();
	AMateria *m2 = new Ice();
	AMateria *m3 = new Cure();
	AMateria *m4 = new Cure();
	AMateria *m5 = new Cure();

	// AMateria *floor_objs[100];
	// int objs = 0;

	me->equip(m0);
	me->equip(m3);
	me->showInventory();
	
	Character *gary = new Character(*me); // gary is a copy of me
	gary->setName("Gary");
	gary->showInventory();
	gary->equip(m1);
	gary->equip(m2);
	gary->showInventory();

	me->equip(m4);
	me->equip(m5);
	me->showInventory();
	
	delete me;
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

	ICharacter* me = new Character("me");

	// the reference is lost so we better do not unequip!
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}
int main()
{
	// testSource();
	//testChars();
	//testCharsCopy();
	fixed_example();

	return 0;
}