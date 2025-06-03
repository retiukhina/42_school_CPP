#include "../include/FragTrap.hpp"

using std::cout;
using std::endl;

FragTrap::FragTrap() : ClapTrap() {
    cout << "FragTrap " << getName() << " called default constructor." 
			<< endl;
}

FragTrap::FragTrap(const string& name)
    : ClapTrap(name, 100, 100, 30)
{
    cout << "FragTrap " << name << " called name-only constructor." 
			<< endl;
}

FragTrap::FragTrap(const string& name
					, unsigned int hitpoints
					, unsigned int energyPoints
					, unsigned int attackDamage
): ClapTrap(name
			, hitpoints
			, energyPoints
			, attackDamage
)
{
	cout << "FragTrap " << name << " called custom constructor." << endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    cout << "FragTrap " << getName() << " called copy constructor." << endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	cout << "Copy FragTrap assignment operator called" << endl;
	if (this != &other) {
	    ClapTrap::operator=(other);
    }
	return (*this);
}

FragTrap::~FragTrap() {
    cout << "FragTrap " << getName() << " called destructor." 
			<< endl;
}

void FragTrap::highFivesGuys() {
    cout << "FragTrap " << getName() << " requests a high five! ✋ Positive vibes only!" << endl;
}