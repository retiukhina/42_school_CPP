#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

Intern::Intern()
    : _count(0) {}

Intern::~Intern() {}

bool Intern::alreadyRegistered(const string& formType) {
    for (int i = 0; i < _count; ++i){
        if (strcmp(formTypes[i], formType) == 0) {
            return true;
        }
    }
    return false;
}

void Intern::registerForm(const string& formType, FormCreator creator) {
    if (!formType || !creator || _count >= MAX_FORM_TYPES) {
        return;
    }

    if (alreadyRegistered(formType)) {
        cerr << "Form type already registered: " << formType << endl;
        return ;
    }
    formTypes[_count] = formType.c_str();
    creators[_count] = creator;
    ++_count;
}

AForm* Intern::makeForm(const string& formType, const string& target) {
   for (int i = 0; i < _count; ++i) {
        if(strcmp(formTypes[i], formType) == 0) {
            return creators[i](target);
        }
   }
}