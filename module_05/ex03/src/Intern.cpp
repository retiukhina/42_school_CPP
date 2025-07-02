#include "../include/Intern.hpp"

Intern::Intern()
    : _count(0) 
{
    registerForm(FORM_TYPE_ROBOTOMY, createRobotomy);
    registerForm(FORM_TYPE_PARDON, createPardon);
    registerForm(FORM_TYPE_SHRUBBERY, createShrubbery);
}

Intern::~Intern() {}

bool Intern::alreadyRegistered(const string& formType) {
    for (int i = 0; i < _count; ++i){
        if (formTypes[i] == formType) {
            return true;
        }
    }
    return false;
}

void Intern::registerForm(const string& formType, FormCreator creator) {
    if (formType.empty() || !creator || _count >= MAX_FORM_TYPES) {
        return ;
    }

    if (alreadyRegistered(formType)) {
        cerr << "Form type already registered: " << formType << endl;
        return ;
    }
    formTypes[_count] = formType.c_str();
    creators[_count] = creator;
    ++_count;
    return ;
}

AForm* Intern::makeForm(const string& formType, const string& target) {
   for (int i = 0; i < _count; ++i) {
        if (formTypes[i] == formType) {
            return creators[i](target);
        }
   }
   cerr << "Error: Unknown form type \"" << formType << "\"." << endl;
   return 0;
}