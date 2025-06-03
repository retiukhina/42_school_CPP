#include "../include/ClapTrap.hpp"

#define DEBIG
using std::cout;
using std::endl;

void ClapTrap::attack(const string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		cout << "ClapTrap " << _name << " attacks " << target
		<< " causing " << _attackDamage << " points of damage!"	<< endl;
		_energyPoints--;
	}
	else {
		cout << "ClapTrap " << _name << " can't damage " << target
			<< ". Energy points left: " << _energyPoints
			<< ". Hit points left: " <<_hitPoints << endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0 && amount <= _hitPoints) {
		cout << "ClapTrap " << _name << " lose " << amount
			<< " hit points!" << endl;
		_hitPoints -= amount;
	}
	else {
		cout << "ClapTrap " << _name << " lost all hit points! " 
            << endl;
	}
    #ifdef DEBUG
    cout << "ClapTrap " << _name << ": " << _hitPoints << " hit points, "
            << _energyPoints << " energy points, " << getAttackDamage() 
            << " damage attack left." << endl;
    #endif
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0) {
		cout << "ClapTrap " << _name << " is repairing itself" <<
			" losing 1 energy point, " << amount << " hitpoints restored." << endl;
		_energyPoints--;
		_hitPoints += amount;
	}
	else {
		cout << "ClapTrap " << _name << " can't repair itself. " <<
			"Energy points left: " << _energyPoints << endl;
	}
}

unsigned int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
    this->_attackDamage += amount;
    cout << "Damage atack amount set to: " << _attackDamage << endl;
}

unsigned int ClapTrap::getHitPoints() const {
    return this->_hitPoints;
}