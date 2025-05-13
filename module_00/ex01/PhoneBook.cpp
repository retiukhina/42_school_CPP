#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	readInput(const std::string& prompt){

	std::string input;
	std::cout << prompt << std::endl;
	std::cin >> input;
	return input;
}

bool PhoneBook::add(){

	Contact newContact;

	//fill contacts data
	newContact.setFirstName(readInput("Enter First Name: "));
	newContact.setLastName(readInput("Enter Last Name: "));
	newContact.setNickName(readInput("Enter Nick Name: "));
	newContact.setPnoneNumber(readInput("Enter Phonw Number: "));
	newContact.setDarkestSecret(readInput("Enter Darkest Secret: "));

	//update index
	contacts[nextIndex] = newContact;
	nextIndex = (nextIndex + 1) % MAX_CONTACTS;
	if (contactCount < MAX_CONTACTS)
		contactCount++;
}
