#include "../include/Contact.hpp"

void Contact::setFirstName(const std::string& input){
	this->firstName = input;
}

void Contact::setLastName(const std::string& input){
	this->lastName = input;
}

void Contact::setNickName(const std::string& input){
	this->nickName = input;
}

void Contact::setPhoneNumber(const std::string& input){
	this->phoneNumber = input;
}

void Contact::setDarkestSecret(const std::string& input){
	this->darkestSecret = input;
}

void Contact::print() const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nick Name: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
