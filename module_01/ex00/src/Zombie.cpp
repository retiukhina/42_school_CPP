#include "../include/Zombie.hpp"

Zombie::Zombie(std::string s) {
	name = s;
}

Zombie::~Zombie() {
	std::cout << "Zombie's " << name << "body and soul reunited. Good buuuy!" << std::endl;
}

void Zombie::announce(void) {
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
