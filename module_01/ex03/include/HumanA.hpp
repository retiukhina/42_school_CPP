#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(const std::string& name, Weapon& weaponA);
		void attack();

	private:
		std::string name;
		Weapon &weaponA;
};
