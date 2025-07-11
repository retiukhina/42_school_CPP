#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include <sstream>

// #define DEBUG

const string Bureaucrat::DEFAULT_NAME = "Bureaucrat";
const int Bureaucrat::DEFAULT_GRADE = 1;

Bureaucrat::Bureaucrat()
	: _name(DEFAULT_NAME)
	, _grade(validateGrade(DEFAULT_GRADE))
{}

Bureaucrat::Bureaucrat(const string& name, int grade)
    : _name(name)
{
    setGrade(grade);
    #ifdef DEBUG
    cout << _name << ": Constructor by name called." << endl;
    #endif
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name)
{
    setGrade(other._grade);
    #ifdef DEBUG
    cout << _name << ": Copy constructor called." << endl;
    #endif
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    #ifdef DEBUG
	cout << "Copy Assignment called" << endl;
    #endif
    return *this;
}

Bureaucrat::~Bureaucrat() {
    #ifdef DEBUG
    cout << _name << ": Destructor called." << endl;
    #endif
}

const string& Bureaucrat::getName() const {
    return _name;
}

const string& Bureaucrat::getDefaultName() const {
    return DEFAULT_NAME;
}

int Bureaucrat::validateGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    return grade;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

int Bureaucrat::getDefaultGrade() const{
    return DEFAULT_GRADE;
}

void Bureaucrat::setGrade(const int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

// Constructor of exception creates the message of error
Bureaucrat::GradeTooHighException::GradeTooHighException()
{
    std::ostringstream oss;
    oss << "Grade too high";
    _message = oss.str();
}

// Constructor of exception creates the message of error
Bureaucrat::GradeTooLowException::GradeTooLowException()
{
    std::ostringstream oss;
    oss << "Grade too low";
    _message = oss.str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return _message.c_str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return _message.c_str();
}

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1) {
        #ifdef DEBUG
        cout << "Grade can't be incremented" << endl;
        #endif
        throw GradeTooHighException();
    }
    _grade--;
    #ifdef DEBUG
    cout << "Grade incremented" << endl;
    #endif
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150){
        #ifdef DEBUG
        cout << "Grade can't be decremented" << endl;
        #endif
        throw GradeTooLowException();
    }
    _grade++;
    #ifdef DEBUG
    cout << "Grade decremented" << endl;
    #endif
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        cout << "\033[32m" << _name << " signed " << form.getName() << " 🙂" << "\033[0m" <<endl;
    } catch (const exception& e) {
        cout << "\033[31m" << _name << " couldn’t sign " << form.getName()
             << " because " << e.what() << " 😢" << "\033[0m" << endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        cout << "\033[32m" << getName() << " executed " << form.getName() << " 🙂" << "\033[0m" << endl;
    } catch (const std::exception& e) {
        cerr << "\033[31m" << getName() << " couldn’t execute " << form.getName()
                  << " because: " << e.what() << " 😢" << "\033[0m" << endl;
    }
}

ostream& operator<<(ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade() << endl;
    return os;
}
