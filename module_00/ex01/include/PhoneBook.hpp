#pragma once

#include <iostream>
#include <sstream>
#include "Contact.hpp"
#include "Print.hpp"

class PhoneBook {
	public:
		static const int MAX_CONTACTS = 8;
		PhoneBook();
		bool add();
		bool search();

	private:
		int			nextIndex;
		int			contactCount;
		Contact		contacts[MAX_CONTACTS];
		std::string	readInput(const std::string& prompt);
};
