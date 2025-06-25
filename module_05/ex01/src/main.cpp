#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

// A Form starts out unsigned.
// A Bureaucrat can sign it only if their grade is high enough (i.e., numerically lower or equal to the gradeToSign required by the form).
// If their grade is too low (numerically too high), the form cannot be signed.

int main() {
    Bureaucrat john("John", 10);
    Form passport("Passport Form", 20, 30);
    john.signForm(passport);

    std::cout << passport << std::endl;
    john.signForm(passport);
    std::cout << passport << std::endl;

    Bureaucrat alice("Alice", 50);
    alice.signForm(passport);
}
