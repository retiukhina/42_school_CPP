#pragma once

#include "AForm.hpp"
#include "FormFactory.hpp"
//#include <cstring>

static const char* const FORM_TYPE_ROBOTOMY = "robotomy";
static const char* const FORM_TYPE_PARDON = "pardon";
static const char* const FORM_TYPE_SHRUBBERY = "shrubbery";

const int MAX_FORM_TYPES = 3;
typedef AForm* (*FormCreator)(const std::string& target);

class Intern {
	private:
		Intern(const Intern& other);
		Intern &operator=(const Intern& other);

		string formTypes[MAX_FORM_TYPES];
		FormCreator creators[MAX_FORM_TYPES];
		int _count;

		void registerForm(const string& formType, FormCreator creator);

		bool alreadyRegistered(const string& formType);

	public:
		Intern();
		~Intern();

		AForm* makeForm(const string& formType, const string& target);
};
