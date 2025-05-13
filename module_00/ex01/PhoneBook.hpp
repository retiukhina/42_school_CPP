#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
	public:
		bool add();

	private:
		int			nextIndex = 0;
		int			contactCount = 0;
		Contact		contacts[MAX_CONTACTS];
		std::string	readInput(const std::string& prompt);
};

#endif
