#pragma once

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	private:
		FragTrap();
		FragTrap& operator=(const FragTrap& other);

	public:
		FragTrap(const string& name);
		FragTrap(const string& name
				, unsigned int hitpoints
				, unsigned int energyPoints
				, unsigned int attackDamage
		);
		FragTrap(const FragTrap& other);
		~FragTrap();

		void attack(const string& target);
		void highFivesGuys(void);
};
