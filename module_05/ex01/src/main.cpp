#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

// A Form starts out unsigned.
// Bureaucrats can sign it only if their grade is high enough (i.e., numerically lower or equal to the gradeToSign required by the form).
// If their grade is too low (numerically too high), the form cannot be signed.

void test_3() {
    cout << "\033[2;23mTest 3: Error, sign grade is too low " << "\033[0m" << endl;
    Bureaucrat Emily("Emily", 50);
    try {
        Form recepy("Recepy Form", 160, 1);
        cout << Emily;
        cout << recepy << endl;
        Emily.signForm(recepy);
    } catch (const exception& e) {
        cerr << "main(): Failed to create Form: " << e.what() << endl;
    }
}

void test_2() {
    cout << "\033[2;23mTest 2: Form has been not signed " << "\033[0m" << endl;
    Bureaucrat alice("Alice", 50);
    try {
        Form passport("Passport Form", 1, 30);
        cout << alice;
        cout << passport << endl;
        alice.signForm(passport);
    } catch (const exception& e) {
        cerr << "main(): Failed to create Form: " << e.what() << endl;
    }
}

void test_1() {
    cout << "\033[2;23mTest 1: Form has been signed " << "\033[0m" << endl;

    Bureaucrat john("John", 10);
    try {
        Form passport("Passport Form", 20, 30);
        cout << john;
        cout << passport << endl;
        john.signForm(passport);
    } catch (const exception& e) {
        cerr << "main(): Failed to create Form: " << e.what() << endl;
    }
}

int main() {
    test_1();
    test_2();
    test_3();
}
