#include "../include/HumanB.hpp"

HumanB::HumanB(const std::string& str)
	: name(str), weaponB(NULL) {}

void HumanB::setWeapon(Weapon& weapB) {
	weaponB = &weapB;
}

void HumanB::attack() {
	if (weaponB) {
		std::cout << name << " attacks with their " << weaponB->getType() << std::endl;
	}
	else {
		std::cout << name << " is unarmed! " << std::endl;
	}
}
