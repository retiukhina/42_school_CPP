#include "../include/FormFactory.hpp"

AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
