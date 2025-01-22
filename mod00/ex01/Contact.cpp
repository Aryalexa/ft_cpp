#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string firstNameV, 
			std::string lastNameV, std::string nicknameV, 
			std::string phoneNumberV, std::string darkestSecretV):
		firstName(firstNameV), 
		lastName(lastNameV), nickname(nicknameV),
		phoneNumber(phoneNumberV), darkestSecret(darkestSecretV) {};

Contact::~Contact() {}

static std::string trimSpaces(std::string str)
{
	size_t new_start = 0;
	while (std::isspace(str[new_start]) and new_start < str.length())
		new_start++;
	str = str.substr(new_start, str.length());
	return str;
}

std::string Contact::readFieldLine(std::string fieldName)
{
	bool valid = false;
	std::string fieldValue;
	while (!valid)
	{
		std::cout << "\t" << fieldName << ": ";
		std::getline(std::cin, fieldValue);
		fieldValue = trimSpaces(fieldValue);
		if (fieldValue.length() > 0)
			valid = true;
	}
	return fieldValue;
}
std::string Contact::readField(std::string fieldName)
{
	std::string fieldValue;
	
	std::cout << "\t" << fieldName << ": ";
	std::cin >> fieldValue;
	if (std::cin.eof())
	{
		std::cout << "bad input" << std:: endl;
		exit(1);
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	return fieldValue;
}

Contact Contact::readContact()
{

	std::string firstName = Contact::readField("First name");
	std::string lastName = Contact::readField("Last name");
	std::string nickname = Contact::readField("Nickname");
	std::string phoneNumber = Contact::readField("Phone number");
	std::string darkestSecret = Contact::readFieldLine("Darkest secret");
	
	Contact c(firstName, lastName, nickname, phoneNumber, darkestSecret);
	return c;
}

static void displayLine(std::string fieldName, std::string fieldValue)
{
	std::cout << "\t" << fieldName << ": " << fieldValue << std::endl;
}

void	Contact::display()
{
	displayLine("First name", firstName);
	displayLine("Last name", lastName);
	displayLine("Nickname", nickname);
	displayLine("Phone number", phoneNumber);
	displayLine("Darkest secret", darkestSecret);

}

std::string Contact::getFirstName()
{
	return firstName;
}
std::string Contact::getLastName()
{
	return lastName;
}
std::string Contact::getNickname()
{
	return nickname;
}
