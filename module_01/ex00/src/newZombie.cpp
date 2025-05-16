#include "../include/Zombie.h"

Zombie*	newZombie(std::string name) {
	Zombie *zombie = new Zombie(name);

	return zombie;
}

