#pragma once

#include <string>
#include <iostream>

using std::string;

class ClapTrap {
	private:		
		string _name;
	
	protected:
		ClapTrap();
		// copy assignment constructor
		ClapTrap& operator=(const ClapTrap& other);
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
		// copy constructor
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		bool operator==(const ClapTrap& other) const;

		void attack(const string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void setAttackDamage(unsigned int amount);
		unsigned int getAttackDamage() const;
		const string& getName(void);
		unsigned int getHitPoints() const;
};

