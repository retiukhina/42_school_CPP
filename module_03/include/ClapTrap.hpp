#pragma once

#include <string>
#include <iostream>

using namespace std;

class ClapTrap {
	private:
		ClapTrap();
		string _Name;
		unsigned int hitPoints; // Representing the health of the ClapTrap
		unsigned int energyPoints;
		unsigned int attackDamage;

	public:
		// Constructor to initialize the name
		ClapTrap(const string& name);
		// Copy constructor
		// ClapTrap(const ClapTrap& other);
		// // Copy assignment operator
		// ClapTrap& operator=(const ClapTrap& other);
		// // Destructor
		~ClapTrap();
		// void attack(const string& target);
		// void takeDamage(unsigned int amount);
		// void beRepaired(unsigned int amount);

		const string& getName(void);
};
