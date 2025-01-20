
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): mem_occ(0)
{
	std::cout << CYAN "MateriaSource default constructor()" RESET << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource &other): mem_occ(other.mem_occ)
{
	std::cout << CYAN "MateriaSource copy constructor()" RESET << std::endl;
	for (int i = 0; i < other.mem_occ; ++i)
		memory[i] = other.memory[i]->clone();
}
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << CYAN "MateriaSource = operator()" RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < mem_occ; ++i)
			delete memory[i];
		mem_occ = other.mem_occ;
		for (int i = 0; i < other.mem_occ; ++i)
			memory[i] = other.memory[i]->clone();
	}
	return *this;
}
MateriaSource::~MateriaSource()
{
	std::cout << MAGENTA "MateriaSource destructor()" RESET << std::endl;
	for (int i = 0; i < mem_occ; ++i)
		delete memory[i];
}
/**
 * Copies the Materia passed as a parameter 
 * and store it in memory so it can be cloned later.
 * (not necessarily unique)
 */
void MateriaSource::learnMateria(AMateria *m)
{
	if (mem_occ == MEMCAP)
		return;
	memory[mem_occ] = m->clone();
	++mem_occ;
	std::cout << "Added to source: " << m->getType() << std::endl;
}
/**
 * Returns a new Materia. 
 * The latter is a copy of the Materia previously learned 
 *  whose type equals the one passed as parameter. 
 * Returns 0 if the type is unknown.
 */
AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < mem_occ; ++i)
	{
		if (memory[i]->getType() == type)
		{
			return memory[i]->clone();
		}
	}
	return 0;
}

void MateriaSource::showLearnt() const
{
	std::cout << "Learnt:" << std::endl;
	
	for (int i = 0; i < mem_occ; ++i)
		std::cout << " " << i << " " << memory[i]->getType() << std::endl;
	
	if (mem_occ == 0)
		std::cout << " nothing" << std::endl;

}
