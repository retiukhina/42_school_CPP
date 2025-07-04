#include "../include/Bureaucrat.hpp"
#include <cassert>

#define DEBUG

void test_5(const string& name, const int grade, bool decrement_exception,
    bool increment_exception, int *num)
{
    cout << "\033[2;23mTest " << *num << ": Check exceptions with incrementing and decrementing grade functions\033[0m" << endl;

    try {
        Bureaucrat a(name, grade);
        #ifdef DEBUG
        cout << a;
        #endif
        a.incrementGrade();
        assert(!increment_exception);
        a.decrementGrade();
        assert(!decrement_exception);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        cerr << e.what() << endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        cerr << e.what() << endl;
    }
    (*num)++;
}

void test_4(const string& name, const int grade, bool expect_exception, int *num) {
    cout << "\033[2;23mTest " << *num << ": Check exceptions with copy constructor function\033[0m" << endl;
    try {
        Bureaucrat a(name, grade);
        assert(!expect_exception);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        cerr << e.what() << endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        cerr << e.what() << endl;
    } catch (...) {
        cerr << "Unknown exception occurred!" << endl;
    }
    (*num)++;
}

void test_3(const string& name, const int grade, bool expect_exception,
    int expected_grade, int *num)
{
    cout << "\033[2;23mTest " << *num << ": Check exceptions with constructor by name\033[0m" << endl;
    try {
        Bureaucrat a(name, grade);
        #ifdef DEBUG
        cout << a;
        #endif
        assert(!expect_exception); // shouldn't reach if an exception is expected
        int g = a.getGrade();
        assert(g = expected_grade);
        #ifdef DEBUG
        cout << a;
        #endif
    } catch (const Bureaucrat::GradeTooHighException &e) {
        cerr << e.what() << endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        cerr << e.what() << endl;
    } catch (...) {
        cerr << "Unknown exception occurred!" << endl;
    }
    (*num)++;
}

void test_2(int *num) {
    cout << "\033[2;23mTest " << *num << ": Check increment and decrement functions\033[0m" << endl;
    Bureaucrat a;
    int g = a.getDefaultGrade();
    a.decrementGrade();
    assert(a.getGrade() == g + 1);
    #ifdef DEBUG
    cout << a;
    #endif
    a.incrementGrade();
    assert(a.getGrade() == g);
    #ifdef DEBUG
    cout << a;
    #endif
    (*num)++;
}

void test_1(int *num) {
    cout << "\033[2;23mTest " << *num << ": Check constructors and copy assignment operator\033[0m" << endl;
    try{
            Bureaucrat a; // default constructor
            assert(a.getGrade() == a.getDefaultGrade());
            #ifdef DEBUG
            cout << a;
            #endif
            Bureaucrat b("Filip", 4); // constructor by name
            #ifdef DEBUG
            cout << b;
            #endif
            assert(b.getGrade() == 4);
            Bureaucrat c(b); // copy constructor
            assert(c.getName() == b.getName());
            assert(c.getGrade() == b.getGrade());
            a = b;
            assert(a.getName() == a.getDefaultName()); // copy assignment operator
            assert(a.getGrade() == b.getGrade()); //copy assignment operator
            b.decrementGrade();
            #ifdef DEBUG
            cout << b;
            #endif
            b.incrementGrade();
            #ifdef DEBUG
            cout << b;
            #endif
    } catch (const Bureaucrat::GradeTooHighException &e) {
        cerr << e.what() << endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        cerr << e.what() << endl;
    } catch (...) {
        cerr << "Unknown exception occurred!" << endl;
    }
    (*num)++;
}

int main(){
    static int num = 1;

    test_1(&num);
    test_2(&num);
    test_3("Johaness", 156, true, 156, &num);
    test_3("Nik", +8, false, +8, &num); // + interpreted as positive number
    test_3("Peter", 0, true, 0, &num);
    test_3("Anna", 1, false, 1, &num);
    test_3("Simon", -3, true, -3, &num);
    test_3("Michael", 151, false, 151, &num);
    test_4("Ben", 267, true, &num);
    test_4("Magda", 45, false, &num);
    test_5("Mira", 1, true, false, &num);
    test_5("Lola", 150, false, false, &num);
    test_5("Shaldon", 33, false, false, &num);
    num = 0;
    return 0;
}
