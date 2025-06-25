#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

class RobotomyRequestForm : public AForm {
	private:
	    std::string _target;
	    static const std::string DEFAULT_TARGET;

	public:
	    RobotomyRequestForm();
	    RobotomyRequestForm(const std::string& target);
	    RobotomyRequestForm(const RobotomyRequestForm& other);
	    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	    ~RobotomyRequestForm();

	    const std::string& getTarget() const;

	    void execute(const Bureaucrat& executor) const;
};

#endif
