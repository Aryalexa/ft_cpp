#pragma once

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const int MEMCAP = 4; // mem max capacity
	AMateria* memory[MEMCAP];
	int mem_occ;
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();
	
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
	void showLearnt() const;
};
