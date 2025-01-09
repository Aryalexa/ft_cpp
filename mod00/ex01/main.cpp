
#include <iostream>
#include <string>
#include "PhoneBook.h"

enum Instruction {
    IAdd,
    ISearch,
    IExit
};

Instruction getInstruction()
{
	std::string input;
	bool valid_instr;

	do
	{
		valid_instr = true;
		std::cout << "Introduce instruction: ";
		std::cin >> input;
		if (input == "ADD")
			return IAdd;
		if (input == "SEARCH")
			return ISearch;
		if (input == "EXIT")
			return IExit;
		valid_instr = false;
	} while (!valid_instr);
	return IExit;
}

int readIndex(size_t numValues)
{
	size_t i;
	std::cout << "Index of the contact you want to see: ";
	// check input and range
	while (!(std::cin >> i) || !(i >= 0 && i < numValues)) {
		std::cin.clear(); // reset error state of std::in
		std::cin.ignore(1000, '\n'); //discard invalid chars in the input buffer..
		// ..up to a newline, preventing an infinite loop
		std::cout << "Invalid input. Please enter a valid index ["<< 0 << "-"<< numValues - 1<< "]: ";
	}
	return i;
}

int main()
{
	Instruction inst;
	PhoneBook phb;
	bool exit = false;
	

	std::cout << "⭐️ The 8-Contacts-PhoneBook ⭐️" << std::endl;
	std::cout << "Possible instructions:" << std::endl;
	std::cout << " ADD" << std::endl;
	std::cout << " SEARCH" << std::endl;
	std::cout << " EXIT" << std::endl;
	while (!exit)
	{
		inst = getInstruction();
		if (inst == IAdd)
		{
			std::cout << std::endl;
			std::cout << "Adding contact..." << std::endl;
			Contact contact = Contact::readContact();
			phb.addContact(contact);
			std::cout << "Contact added ✨" << std::endl;
			std::cout << std::endl;
		}
		else if (inst == ISearch)
		{
			std::cout << std::endl;
			phb.displayContacts();
			if (phb.getCurrentSize() > 0)
			{
				int index = readIndex(phb.getCurrentSize());
				phb.displayContactDetails(index);
			}
			std::cout << std::endl;
		}
		else if (inst == IExit)
			exit = true;
	}
	return 0;

}