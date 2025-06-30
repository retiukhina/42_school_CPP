#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const string formType, const string target) {
	cout << formType << " " << target << endl;
	AForm *f = new RobotomyRequestForm;
	return f;
}
