#pragma once

#include "AForm.hpp"

class Intern {
	private:
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

	public:
		Intern();
		~Intern();

		AForm* makeForm(const string formType, const string target) ;
};
