#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

void testShrubberyForm() {
    cout << "\033[2;23mTest 1: ShrubberyCreationForm\033[0m" << endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm form("home");

        bob.signForm(form);
        bob.executeForm(form);
    } catch (const std::exception& e) {
        cerr << "Shrubbery Error: " << e.what() << endl;
    }
}

void testRobotomyForm() {
    cout << "\033[2;23mTest 2: RobotomyRequestForm\033[0m" << endl;
    try {
        Bureaucrat alice("Alice", 40); // grade high enough to sign and execute
        RobotomyRequestForm form("target_robot");

        alice.signForm(form);
        alice.executeForm(form);
    } catch (const std::exception& e) {
        cerr << "Robotomy Error: " << e.what() << endl;
    }
}

void testPresidentialPardonForm() {
    cout << "\033[2;23mTest 3: PresidentialPardonForm\033[0m" << endl;
    try {
        Bureaucrat zaphod("Zaphod", 1); // top grade
        PresidentialPardonForm form("Ford Prefect");

        zaphod.signForm(form);
        zaphod.executeForm(form);
    } catch (const std::exception& e) {
        cerr << "Pardon Error: " << e.what() << endl;
    }
}

void testFailExecution() {
    cout << "\033[2;23mTest 4: Form has been not signed, not executed\033[0m" << endl;
    try {
        Bureaucrat joe("Joe", 150);
        ShrubberyCreationForm form("fail_test");

        joe.signForm(form); // Should fail or pass depending on form’s sign grade
        joe.executeForm(form); // Should fail to execute
    } catch (const std::exception& e) {
        cerr << "Fail Execution Error: " << e.what() << endl;
    }
}

int main() {
    testShrubberyForm();
    testRobotomyForm();
    testPresidentialPardonForm();
    testFailExecution();

    return 0;
}

