
#pragma once

#include <string>
#include <iostream>

class Brain
{
private:
	static const int NIDEAS = 100;
	std::string ideas[Brain::NIDEAS];
	int curIdea;

public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();
	void addIdea(const std::string &idea);
	void showIdeas() const;
};
