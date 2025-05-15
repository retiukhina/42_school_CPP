#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>

class Contact{
	public:
		// setters
		void		setFirstName(const std::string& firstName);
		void		setLastName(const std::string& lastName);
		void		setNickName(const std::string& nickName);
		void		setPhoneNumber(const std::string& lastName);
		void		setDarkestSecret(const std::string& nickName);

		void print() const;
		void printSummary(int i) const;
		bool isFilled() const;
		std::string printSingleContact(const int index) const;

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string phoneNumber;
		std::string darkestSecret;

		std::string formatField(const std::string& field) const;
};
