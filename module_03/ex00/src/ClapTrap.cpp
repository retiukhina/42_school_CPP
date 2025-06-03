#include "../include/ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap(const string& name)
	: _name(name)
	, _hitPoints(10)
	, _energyPoints(10)
	, _attackDamage(0)
{
		cout << _name << " called name-only constructor." << endl;
}

ClapTrap::ClapTrap(const string& name
					, unsigned int hitpoints
					, unsigned int energyPoints
					, unsigned int attackDamage
):
	_name(name)
	, _hitPoints(hitpoints)
	, _energyPoints(energyPoints)
	, _attackDamage(attackDamage)
{
	cout << _name << " called custom constructor." << endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	cout << "Copy assignment operator called" << endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
	}
	return (*this);
}

bool ClapTrap::operator==(const ClapTrap& other) const {
	return (_name == other._name
		&& _hitPoints == other._hitPoints
		&& _energyPoints == other._energyPoints
		&& _attackDamage == other._attackDamage);
}

const string& ClapTrap::getName(void) {
	return _name;
}

ClapTrap::~ClapTrap() {
	cout << _name << " called destructor" << endl;
}

