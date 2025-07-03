#include "../include/Bureaucrat.hpp"

void test_2(int *num) {
    cout << "\033[2;23mTest " << *num << "\033[0m" << endl;
    try {
            Bureaucrat a;
            cout << a << endl;
            Bureaucrat b("Filip", -4);
            a = b;
            b.decrementGrade();
            cout << b << endl;
            b.incrementGrade();
            cout << b << endl;
    } catch (const Bureaucrat::GradeTooHighException &e) {
        cerr << e.what() << endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        cerr << e.what() << endl;
    } catch (...) {
        cerr << "Unknown exception occurred!" << endl;
    }
    (*num)++;
}

void test_1(const string& name, const int grade, int *num) {
    cout << "\033[2;23mTest " << *num << "\033[0m" << endl;
    try {
        Bureaucrat b(name, grade);
        cout << b << endl;
        b.decrementGrade();
        b.incrementGrade();
        cout << b << endl;
    } catch (const Bureaucrat::GradeTooHighException &e) {
        cerr << e.what() << endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        cerr << e.what() << endl;
    } catch (...) {
        cerr << "Unknown exception occurred!" << endl;
    }
    (*num)++;
}

int main() {
    static int num = 1;

    test_1("Peter", 0, &num);
    test_1("Anna", 1, &num);
    test_1("Peter", -3, &num);
    test_1("Peter", 151, &num);
    test_2(&num);
}
