#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <iostream>
#include <iomanip>


class PhoneBook
{
private:
	static const int MAX_PHB = 8;  // Fixed size of the array
	static const int F_WDTH = 10;  // width for formatting
    Contact contacts[MAX_PHB];     // C-style array of fixed size
    int currentSize;     
	int lastAdded;
public:
	PhoneBook();
	~PhoneBook();
	void addContact(Contact c);
	int	 getCurrentSize();
	void displayContacts();
	void displayContactDetails(size_t index);

};



#endif