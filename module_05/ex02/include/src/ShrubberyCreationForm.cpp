#include "../include/ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::DEFAULT_TARGET = "default_target";

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", defaultGradeToSign, defaultGradeToExecute)
	, _target(DEFAULT_TARGET)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const string& target)
	: AForm("ShrubberyCreationForm", 145, 137)
	, _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
	, _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

const string& ShrubberyCreationForm::getTarget() const {
	return _target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    // check if form is signed
    if (!ifSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    // Your shrubbery ASCII generation here
    ofstream out((_target + "_shrubbery").c_str());
    if (!out)
        return;
    out << "       _-_\n"
           "    /~~   ~~\\\n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\ //  ~\n"
           "_- -   | | _- _\n"
           "  _ -  | |   -_\n"
           "      // \\\n";
    out.close();
}

ostream &operator<<(ostream &os, const ShrubberyCreationForm &form) {
	os << "Form: " << form.getName()
		<< "Target: " << form.getTarget()
		<< ". Grade to sign: " << form.getGradeToSign()
		<< ". Grade to execute: " << form.getGradeToExecute()
	;
	return os;
}

