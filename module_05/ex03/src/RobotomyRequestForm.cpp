#include "../include/RobotomyRequestForm.hpp"

const std::string RobotomyRequestForm::DEFAULT_TARGET = "default_target";

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45)
	, _target(DEFAULT_TARGET)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45)
	, _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other)
	, _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string& RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!ifSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    cout << "* Drilling noises *" << endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
        cout << _target << " has been robotomized successfully." << endl;
    else
        cout << "Robotomy failed on " << _target << "." << endl;
}
