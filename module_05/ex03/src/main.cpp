#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"

void test_5(const string& formType, const string& target) {
    cout << "\033[2;23mTest 5: Unknown Form. " << "\033[0m" << endl;
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

void test_4(const string& formType, const string& target) {
    cout << "\033[2;23mTest 4: Form " << formType << " signed and executed." << "\033[0m" << endl;
    Intern intern;

    AForm* form = NULL;
    try {
        form = intern.makeForm(formType, target);
        Bureaucrat boss("Moss", 130);
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

void test_3(const string& formType, const string& target) {
    cout << "\033[2;23mTest 3: Form " << formType << " signed but not executed." << "\033[0m" << endl;
    Intern intern;

    AForm* form = NULL;
    try {
        form = intern.makeForm(formType, target);
        Bureaucrat boss("Moss", 15);
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

void test_2(const string& formType, const string& target) {
    cout << "\033[2;23mTest 2: Form " << formType << " not signed and that's why not executed." << "\033[0m" << endl;
    Intern intern;

    AForm* form = NULL;
    try {
        form = intern.makeForm(formType, target);
        Bureaucrat boss("Moss", 35);
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
    test_2(FORM_TYPE_PARDON, "Turanga Leela");
    test_3(FORM_TYPE_PARDON, "Philip J. Fry");
    test_4(FORM_TYPE_SHRUBBERY, "Amy Wong");
    test_5("Unknown", "Shaldon");

    return 0;
}

