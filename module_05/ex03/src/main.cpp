#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

AForm* createRobotomy(const string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPardon(const string& target) {
    return new PresidentialPardonForm(target);
}

AForm* createShrubbery(const string& target) {
    return new ShrubberyCreationForm(target);
}

// Function to call factory
void test_1(const string& formType, FormCreator f, const string& target) {
    cout << "\033[2;23mTest 1\033[0m" << endl;
    Intern intern;

	intern.registerForm(formType, f);
    AForm* form = nullptr;
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
    test_1(FORM_TYPE_ROBOTOMY, createRobotomy, "Bender");

    return 0;
}

