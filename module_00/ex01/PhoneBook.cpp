#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : nextIndex(0), contactCount(0) {}

std::string	PhoneBook::readInput(const std::string& prompt){

	std::string input;
	do {
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
	} while(input.empty());
	return input;
}

bool PhoneBook::add(){

	Contact c;

	//fill contacts data
	c.setFirstName(readInput("Enter First Name: "));
	c.setLastName(readInput("Enter Last Name: "));
	c.setNickName(readInput("Enter Nick Name: "));
	c.setPhoneNumber(readInput("Enter Phone Number: "));
	c.setDarkestSecret(readInput("Enter Darkest Secret: "));

	//update index
	contacts[nextIndex] = c;
	nextIndex = (nextIndex + 1) % MAX_CONTACTS;
	if (contactCount < MAX_CONTACTS)
		contactCount++;
	return true;
}
