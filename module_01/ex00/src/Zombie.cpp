#include "../include/Zombie.hpp"

Zombie::Zombie(std::string s)
	: _name(s)
{}

Zombie::~Zombie() {
	std::cout << "Zombie's " << _name << "body and soul reunited. Good buuuy!" << std::endl;
}

void Zombie::announce(void) {
		std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
