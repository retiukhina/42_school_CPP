#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

void testShrubberyForm() {
    cout << "\033[2;23mTest: ShrubberyCreationForm\033[0m" << endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm form("home");

        bob.signForm(form);
        bob.executeForm(form);
    } catch (const std::exception& e) {
        cerr << "Shrubbery Error: " << e.what() << endl;
    }
    cout << endl;
}

void testRobotomyForm() {
    cout << "\033[2;23mTest: RobotomyRequestForm\033[0m" << endl;
    try {
        Bureaucrat alice("Alice", 40); // grade high enough to sign and execute
        RobotomyRequestForm form("target_robot");

        alice.signForm(form);
        alice.executeForm(form);
    } catch (const std::exception& e) {
        cerr << "Robotomy Error: " << e.what() << endl;
    }
    cout << endl;
}

void testPresidentialPardonForm() {
    cout << "\033[2;23mTest: PresidentialPardonForm\033[0m" << endl;
    try {
        Bureaucrat zaphod("Zaphod", 1); // top grade
        PresidentialPardonForm form("Ford Prefect");

        zaphod.signForm(form);
        zaphod.executeForm(form);
    } catch (const std::exception& e) {
        cerr << "Pardon Error: " << e.what() << endl;
    }
    cout << endl;
}

void testFailExecution() {
    cout << "\033[2;23mTest: Execution with Low Grade\033[0m" << endl;
    try {
        Bureaucrat joe("Joe", 150);
        ShrubberyCreationForm form("fail_test");

        joe.signForm(form); // Should fail or pass depending on form’s sign grade
        joe.executeForm(form); // Should fail to execute
    } catch (const std::exception& e) {
        cerr << "Fail Execution Error: " << e.what() << endl;
    }
    cout << endl;
}

void test_1(const string formType, const string name) {
    cout << "\033[2;23mTest 1\033[0m" << endl;
    Intern someRandomIntern;

    AForm* form;
    try {
        form = someRandomIntern.makeForm(formType, name);
        Bureaucrat boss("Moss", 1);
        boss.signForm(*form);
        boss.executeForm(*form);
    }
    catch(exception& e) {
    	cerr << "Error: " << e.what() << endl;
    }
    if (form)
    	delete form;
}

int main() {
    test_1("robotomy request", "Bender");
    testShrubberyForm();
    testRobotomyForm();
    testPresidentialPardonForm();
    testFailExecution();

    return 0;
}

