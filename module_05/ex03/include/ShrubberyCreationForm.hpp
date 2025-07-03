#pragma once

#include "AForm.hpp"
#include <fstream>

using std:: ofstream;

class ShrubberyCreationForm: public AForm {
	private:
		string _target;
		static const string DEFAULT_TARGET;

	public:
		ShrubberyCreationForm();
		enum { defaultGradeToSign = 145, defaultGradeToExecute = 137 };
		ShrubberyCreationForm(const string& target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		const string& getTarget() const;
    	void execute(const Bureaucrat& executor) const;
};

ostream& operator<<(ostream& os, const ShrubberyCreationForm& form);
