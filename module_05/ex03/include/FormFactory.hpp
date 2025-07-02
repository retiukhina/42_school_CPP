#pragma once

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm* createRobotomy(const std::string& target);
AForm* createPardon(const std::string& target);
AForm* createShrubbery(const std::string& target);