#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

//A Bureaucrat must have grade ≤ 25 to sign the form.
//A Bureaucrat must have grade ≤ 5 to execute the form.

const std::string PresidentialPardonForm::DEFAULT_TARGET = "default_target";

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5)
	, _target(DEFAULT_TARGET)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5)
	, _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string& PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!ifSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    cout << _target << " has been pardoned by Zaphod Beeblebrox." << endl;
}
