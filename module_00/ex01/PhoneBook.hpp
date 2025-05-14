#pragma once

#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
	public:
		PhoneBook();
		bool add();
		bool search();

	private:
		int			nextIndex;
		int			contactCount;
		Contact		contacts[MAX_CONTACTS];
		std::string	readInput(const std::string& prompt);
};
