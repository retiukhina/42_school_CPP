#include "../include/AForm.hpp"

AForm::AForm()
    : _name("AForm")
    , _gradeToSign(defaultGradeToSign)
    , _gradeToExecute(defaultGradeToExecute)
    , _ifSigned(false)
{}

AForm::AForm(const string& name)
    : _name(name)
    , _gradeToSign(defaultGradeToSign)
    , _gradeToExecute(defaultGradeToExecute)
    , _ifSigned(false)
{}

AForm::AForm(const string& name, int sGrade, int eGrade)
    : _name(name)
    , _gradeToSign(checkGradeToSign(sGrade))
    , _gradeToExecute(eGrade)
    , _ifSigned(false)
{}

AForm::AForm(const AForm& other)
    : _name(other._name)
    , _gradeToSign(other._gradeToSign)
    , _gradeToExecute(other._gradeToExecute)
    , _ifSigned(other._ifSigned)
{}

AForm &AForm::operator=(const AForm& other) {
    if (this != &other) {
        _ifSigned = other._ifSigned;
    }
    return *this;
}

AForm::~AForm() {}

const string& AForm::getName() const {
    return _name;
}

bool AForm::ifSigned() const {
    return _ifSigned;
}

int AForm::checkGradeToSign(const int grade){
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    else if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    return grade;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _ifSigned = true;
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

ostream &operator<<(ostream &os, const AForm &form) {
	os << "Form: " << form.getName()
		<< ". Grade to sign: " << form.getGradeToSign()
		<< ". Grade to execute: " << form.getGradeToExecute()
	;
	return os;
}
