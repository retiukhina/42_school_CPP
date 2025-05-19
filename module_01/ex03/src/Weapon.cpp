#include "../include/Weapon.hpp"

Weapon::Weapon(const std::string& Value)
	:	type(Value) {}

const std::string& Weapon::getType() const {
	return type;
}

void Weapon::setType(const std::string& newValue) {
	type = newValue;
}
