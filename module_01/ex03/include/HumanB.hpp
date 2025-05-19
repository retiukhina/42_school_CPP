#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(const std::string& name);
		void attack();
		void setWeapon(Weapon& weapB);

	private:
		std::string name;
		Weapon *weaponB;
};
