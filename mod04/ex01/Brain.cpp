
#include "Brain.hpp"

Brain::Brain(): curIdea(0)
{
	std::cout << "Brain default constructor()🧠" << std::endl;
}
Brain::Brain(const Brain &other): curIdea(other.curIdea)
{
	for (int i = 0; i < other.curIdea; ++i)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor()🧠" << std::endl;
}
Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain = operator()🧠" << std::endl;
	if (this != &other)
	{
		curIdea = other.curIdea;
		for (int i = 0; i < other.curIdea; ++i)
			ideas[i] = other.ideas[i];	
	}
	return *this;
}
Brain::~Brain()
{
	std::cout << "Brain destructor()🧠" << std::endl;
}
void Brain::addIdea(const std::string &idea)
{
	if (curIdea == NIDEAS)
		return;
	ideas[curIdea] = idea;
	++curIdea;
}
void Brain::showIdeas() const
{
	for (int i = 0; i < curIdea; ++i)
		std::cout << i+1 << ". " << ideas[i] << std::endl;
}

