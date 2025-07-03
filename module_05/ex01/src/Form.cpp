#include "../include/Form.hpp"

Form::Form()
    : _name("Form")
    , _gradeToSign(defaultGradeToSign)
    , _gradeToExecute(defaultGradeToExecute)
    , _ifSigned(false)
{}

Form::Form(const string& name)
    : _name(name)
    , _gradeToSign(defaultGradeToSign)
    , _gradeToExecute(defaultGradeToExecute)
    , _ifSigned(false)
{}

Form::Form(const string& name, int sGrade, int eGrade)
    : _name(name)
    , _gradeToSign(checkGrade(sGrade))
    , _gradeToExecute(checkGrade(eGrade))
    , _ifSigned(false)
{}

Form::Form(const Form& other)
    : _name(other._name)
    , _gradeToSign(other._gradeToSign)
    , _gradeToExecute(other._gradeToExecute)
    , _ifSigned(other._ifSigned)
{}

Form &Form::operator=(const Form& other) {
    if (this != &other) {
        _ifSigned = other._ifSigned;
    }
    return *this;
}

Form::~Form() {}

const string& Form::getName() const {
    return _name;
}

bool Form::ifSigned() const {
    return _ifSigned;
}

int Form::checkGrade(const int grade){
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    else if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    return grade;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _ifSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

ostream &operator<<(ostream &os, const Form &form) {
	os << "Form: " << form.getName()
		<< ". Grade to sign: " << form.getGradeToSign()
		<< ". Grade to execute: " << form.getGradeToExecute()
	;
	return os;
}