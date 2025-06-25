#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
	private:
	    std::string _target;
	    static const std::string DEFAULT_TARGET;
	
	public:
	    PresidentialPardonForm();
	    PresidentialPardonForm(const std::string& target);
	    PresidentialPardonForm(const PresidentialPardonForm& other);
	    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	    ~PresidentialPardonForm();
	
	    const std::string& getTarget() const;
	
	    void execute(const Bureaucrat& executor) const;
};

#endif
