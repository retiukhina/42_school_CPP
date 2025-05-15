#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0), contactCount(0) {}

std::string	PhoneBook::readInput(const std::string& prompt) {
	std::string input;

	do {
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
		// Remove all spaces and tabs from input to check if it's "visibly empty"
		std::string trimmed = input;
		trimmed.erase(std::remove_if(trimmed.begin(), trimmed.end(), ::isspace), trimmed.end());

		if (trimmed.empty()) {
			std::cout << "Input cannot be empty. Please enter valid data." << std::endl;
		} else {
			break; // input is valid
		}
	} while (true);

	return input;
}

bool PhoneBook::search() {
	int			index;
	int			max = PhoneBook::MAX_CONTACTS;
	std::string	output;
	std::string	input;

	printContactsPreview(contacts, max);
	std::cout << "Enter contact's index: " << std::endl;
	std::getline(std::cin, input);
	if (input == "EXIT")
		return false;
	std::istringstream iss(input);
	if (!(iss >> index)) {
		std::cerr << "Invalid index!" << std::endl;
	}
	else if (index > contactCount || index > PhoneBook::MAX_CONTACTS || index < 1) {
		std::cout << "Sorry. There is no contact with index " << index << std::endl;
	}
	else {
		std::cout << contacts[index - 1].printSingleContact(index) << std::endl;
	}
	return true;
}

bool PhoneBook::add() {
	Contact c;

	//set contacts data
	c.setFirstName(readInput("Enter First Name: "));
	c.setLastName(readInput("Enter Last Name: "));
	c.setNickName(readInput("Enter Nick Name: "));
	c.setPhoneNumber(readInput("Enter Phone Number: "));
	c.setDarkestSecret(readInput("Enter Darkest Secret: "));

	// store the contact and update index
	contacts[nextIndex] = c;
	nextIndex = (nextIndex + 1) % PhoneBook::MAX_CONTACTS;
	if (contactCount < PhoneBook::MAX_CONTACTS)
		contactCount++;
	return true;
}
