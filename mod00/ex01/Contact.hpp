#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <cctype>
#include <limits>


class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	static std::string readField(std::string fieldName);
	static std::string readFieldLine(std::string fieldName);

public:
	Contact();
	Contact(std::string firstName, 
			std::string lastName, std::string nickname, 
			std::string phoneNumber, std::string darkestSecret);
	~Contact();
	static Contact readContact();
	void	display();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
};

#endif