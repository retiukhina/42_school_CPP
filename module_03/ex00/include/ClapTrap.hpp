#pragma once

#include <string>
#include <iostream>

using std::string;

class ClapTrap {
	private:
		ClapTrap();
		ClapTrap& operator=(const ClapTrap& other);
		
		string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
		
		public:
		ClapTrap(const string& name);
		ClapTrap(const string& name
			, unsigned int hitpoints
			, unsigned int energyPoints
			, unsigned int attackDamage
		);
		ClapTrap(const ClapTrap& other);
		bool operator==(const ClapTrap& other) const;
		~ClapTrap();
		void attack(const string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void setAttackDamage(unsigned int amount);
		unsigned int getAttackDamage() const;
		const string& getName(void);
		unsigned int getHitPoints() const;
};

