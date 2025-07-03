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

int Bureaucrat::validateGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException(grade);
    if (grade > 150)
        throw GradeTooLowException(grade);
    return grade;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::setGrade(const int grade) {
    if (grade < 1)
        throw GradeTooHighException(grade);
    else if (grade > 150)
        throw GradeTooLowException(grade);
    _grade = grade;
}

// Constructor of exception creates the message of error
Bureaucrat::GradeTooHighException::GradeTooHighException(int grade)
{
    std::ostringstream oss;
    oss << "Grade too high: " << grade;
    _message = oss.str();
}

// Constructor of exception creates the message of error
Bureaucrat::GradeTooLowException::GradeTooLowException(int grade)
{
    std::ostringstream oss;
    oss << "Grade too low: " << grade;
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
    if (_grade - 1 < 1)
        throw GradeTooHighException(_grade);
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooLowException(_grade);
    _grade++;
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        cout << _name << " signed " << form.getName() << endl;
    } catch (const exception& e) {
        cout << _name << " couldn’t sign " << form.getName()
             << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << getName() << " couldn’t execute " << form.getName()
                  << " because: " << e.what() << std::endl;
    }
}

ostream& operator<<(ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
