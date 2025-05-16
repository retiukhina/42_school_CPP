#include "../include/Zombie.hpp"

Zombie::Zombie() {
	name = "";
}

Zombie::~Zombie() {
	std::cout << "Zombie's " << name << " body and soul reunited. Good buuuy!" << std::endl;
}

void Zombie::setName(std::string s) {
	name = s;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
