#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

const string Bureaucrat::DEFAULT_NAME = "Bureaucrat";
const int Bureaucrat::DEFAULT_GRADE = 0;

Bureaucrat::Bureaucrat()
	: _name(DEFAULT_NAME)
	, _grade(DEFAULT_GRADE)
{}

Bureaucrat::Bureaucrat(const string& name, int grade)
    : _name(name)
{
    setGrade(grade);
    cout << _name << ": Constructor by name called." << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name)
{
    setGrade(other._grade);
    cout << _name << ": Copy constructor called." << endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
	cout << "Copy Assignment" << endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    cout << _name << ": Destructor called." << endl;
}

const string& Bureaucrat::getName() const {
    return _name;
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

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        cout << _name << " signed " << form.getName() << endl;
    } catch (const exception& e) {
        cout << _name << " couldn’t sign " << form.getName()
             << " because " << e.what() << std::endl;
    }
}

ostream& operator<<(ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << " bureacrat grade " << bureaucrat.getGrade() << endl;
    return os;
}
