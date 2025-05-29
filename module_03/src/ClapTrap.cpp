#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(const string&name)
	: _Name(name)
	, hitPoints(10)
	, energyPoints(10)
	, attackDamage(0)
{
		cout << "Default constructor called" << endl;
}

const string& ClapTrap::getName(void) {
	return _Name;
}

ClapTrap::~ClapTrap() {
	cout << _Name << " Called destructor" << endl;
}
