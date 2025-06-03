#pragma once

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

using std::string;

class ScavTrap: public ClapTrap {
	public:
		ScavTrap(const string& name);
		ScavTrap(const string& name
				, unsigned int hitpoints
				, unsigned int energyPoints
				, unsigned int attackDamage
		);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		void attack(const string& target);
		void guardGate();
	
	private:
		ScavTrap();
		ScavTrap& operator=(const ScavTrap& other);

};

