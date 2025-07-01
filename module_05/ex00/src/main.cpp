#include "../include/Bureaucrat.hpp"

void test(const string& name, const int grade) {
    static int num = 1;
    cout << "\033[2;23mTest " << num << "\033[0m" << endl;
    try {
        Bureaucrat b(name, grade);
        std::cout << "Bureaucrat created successfully!" << std::endl;
        b.decrementGrade();
        b.incrementGrade();
        cout << b;
    } catch (const Bureaucrat::GradeTooHighException &e) {
        cerr << e.what() << endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        cerr << e.what() << endl;
    } catch (...) {
        std::cerr << "Unknown exception occurred!" << std::endl;
    }
    num++;
}

int main() {
    test("Peter", 0);
    test("Anna", 1);
    test("Peter", -3);
    test("Peter", 151);
}
