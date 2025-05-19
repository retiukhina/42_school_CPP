#include "../include/HumanA.hpp"

HumanA::HumanA(const std::string& str, Weapon& weap)
	: name(str), weaponA(weap) {}

void HumanA::attack() {
	std::cout << name << " attacks with their " << weaponA.getType() << std::endl;
}
