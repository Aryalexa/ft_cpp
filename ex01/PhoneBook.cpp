#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	currentSize = 0;
	lastAdded = -1;
}
PhoneBook::~PhoneBook() {}


void PhoneBook::addContact(Contact c)
{
	lastAdded = (lastAdded + 1) % MAX_PHB;
	contacts[lastAdded] = c;
	currentSize++;
	if (currentSize > MAX_PHB)
		currentSize = MAX_PHB;
}

int PhoneBook::getCurrentSize()
{
	return currentSize;
}

static std::string truncateField(std::string str, int max)
{
	if ((int)str.length() > max)
		return str.substr(0, max - 1) + '.';
	return str;
}

/**
 *  4 cols: index, first name, last name, nickname
 */
static void displayLine(size_t index, Contact c, int w)
{
	//int width = 10;
	std::cout << std::setfill(' ') << std::right << std::setw(w) << index << "|";
	std::cout << std::setw(w) << truncateField(c.getFirstName(), w) << "|";
	std::cout << std::setw(w) << truncateField(c.getLastName(), w) << "|";
	std::cout << std::setw(w) << truncateField(c.getNickname(), w) << std::endl;
}
void PhoneBook::displayContacts()
{
	std::cout << std::setfill(' ') << std::right << std::setw(F_WDTH) << "INDEX" << " ";
	std::cout << std::right << std::setw(F_WDTH) << "FIRST NAME" << " ";
	std::cout << std::right << std::setw(F_WDTH) << "LAST NAME" << " ";
	std::cout << std::right << std::setw(F_WDTH) << "NICKNAME" << std::endl;
	std::cout << std::setfill('-') << std::setw(F_WDTH * 4 + 3)  << "-" << std::endl;
	if (currentSize == 0)
		std::cout << "No contacts yet." << std::endl;
	for (int i = 0; i < currentSize; i++)
		displayLine(i, contacts[i], F_WDTH);
}

void PhoneBook::displayContactDetails(size_t index)
{
	std::cout << "Contact "<< index << std::endl;
	contacts[index].display();
}