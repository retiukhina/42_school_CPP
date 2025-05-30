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

const string& ClapTrap::getName(void) {
	return _name;
}

ClapTrap::~ClapTrap() {
	cout << _name << " called destructor" << endl;
}

void ClapTrap::attack(const string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		cout << "ClapTrap" << _name << " attacks " << target
		<< " causing " << _attackDamage << " points of damage!"	<< endl;
		_energyPoints--;
	}
	else {
		cout << "ClapTrap" << _name << " can't damage " << target
			<< ". Energy points left: " << _energyPoints
			<< ". Hit points left: " <<_hitPoints << endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		cout << "ClapTrap " << _name << " lose " << amount
			<< " hit points!" << endl;
		_hitPoints -= amount;
	}
	else {
		cout << "ClapTrap " << _name << "has no hit points!" << endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0) {
		cout << "ClapTrap" << _name << " is repairing itself" <<
			" losing 1 energy point." << endl;
		_energyPoints--;
		_hitPoints += amount;
	}
	else {
		cout << "ClapTrap" << _name << " can't repair itself. " <<
			". Energy points left: " << _energyPoints << endl;
		_energyPoints--;
	}
}

unsigned int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}
