
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): mem_cnt(0)
{
	std::cout << CYAN "💠MateriaSource default constructor()" RESET << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource &other): mem_cnt(other.mem_cnt)
{
	std::cout << CYAN "💠MateriaSource copy constructor()" RESET << std::endl;
	for (int i = 0; i < other.mem_cnt; ++i)
		memory[i] = other.memory[i]->clone();
}
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << CYAN "💠MateriaSource = operator()" RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < mem_cnt; ++i)
			delete memory[i];
		mem_cnt = other.mem_cnt;
		for (int i = 0; i < other.mem_cnt; ++i)
			memory[i] = other.memory[i]->clone();
	}
	return *this;
}
MateriaSource::~MateriaSource()
{
	std::cout << MAGENTA "💠MateriaSource destructor()" RESET << std::endl;
	for (int i = 0; i < mem_cnt; ++i)
		delete memory[i];
}
/**
 * Copies the Materia passed as a parameter 
 * and store it in memory so it can be cloned later.
 * (not necessarily unique)
 */
void MateriaSource::learnMateria(AMateria *m)
{
	if (mem_cnt == MEM_MAX)
		return;
	memory[mem_cnt] = m->clone();
	++mem_cnt;
	std::cout << "💠Added to source: " << m->getType() << std::endl;
}
/**
 * Returns a new Materia. 
 * The latter is a copy of the Materia previously learned 
 *  whose type equals the one passed as parameter. 
 * Returns 0 if the type is unknown.
 */
AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < mem_cnt; ++i)
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
	std::cout << "💠Learnt:" << std::endl;
	
	for (int i = 0; i < mem_cnt; ++i)
		std::cout << " " << i << " " << memory[i]->getType() << std::endl;
	
	if (mem_cnt == 0)
		std::cout << " nothing" << std::endl;

}
