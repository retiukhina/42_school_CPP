#include "../include/ScavTrap.hpp"

using std::cout;
using std::endl;

ScavTrap::ScavTrap() : ClapTrap() {
    cout << "ScavTrap " << getName() << " called default constructor." 
			<< endl;
}

ScavTrap::ScavTrap(const string& name)
    : ClapTrap(name, 100, 50, 20)
{
    cout << "ScavTrap " << name << " called name-only constructor." 
			<< endl;
}

ScavTrap::ScavTrap(const string& name
					, unsigned int hitpoints
					, unsigned int energyPoints
					, unsigned int attackDamage
): ClapTrap(name
			, hitpoints
			, energyPoints
			, attackDamage
)
{
	cout << "ScavTrap " << name << " called custom constructor." << endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    cout << "ClapTrap " << getName() << " called copy assignment operator." << endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	cout << "Copy ScavTrap assignment operator called" << endl;
	if (this != &other) {
	    ClapTrap::operator=(other);
    }
	return (*this);
}

ScavTrap::~ScavTrap() {
    cout << "ScavTrap " << getName() << " called destructor." 
			<< endl;
}

void ScavTrap::guardGate() {
    cout << "ScavTrap " << getName() << " now in Gate keeper mode." 
			<< endl;
}