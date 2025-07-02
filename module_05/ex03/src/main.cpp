#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

void test_2(const string& formType, const string& target) {
    cout << "\033[2;23mTest 2: Unknown Form. " << "\033[0m" << endl;
    Intern intern;

    AForm* form = NULL;
    try {
        form = intern.makeForm(formType, target);
        Bureaucrat boss("Moss", 1);
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
        }
    }
    catch(exception& e) {
       cerr << "Error: " << e.what() << endl;
    }
    if (form)
        delete form;
}

void test_1(const string& formType, const string& target) {
    cout << "\033[2;23mTest 1: Form " << formType << " signed and executed." << "\033[0m" << endl;
    Intern intern;

    AForm* form = NULL;
    try {
        form = intern.makeForm(formType, target);
        Bureaucrat boss("Moss", 1);
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
        }
    }
    catch(exception& e) {
       cerr << "Error: " << e.what() << endl;
    }
    if (form)
        delete form;
}

int main() {
    test_1(FORM_TYPE_ROBOTOMY, "Bender");
    test_2("Unknown", "Shaldon");

    return 0;
}

