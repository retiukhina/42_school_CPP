#include "../include/ScavTrap.hpp"

#define DEBIG
using std::cout;
using std::endl;

void ScavTrap::attack(const string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		cout << "ScavTrap " << getName() << " attacks " << target
		<< " causing " << _attackDamage << " points of damage!"	<< endl;
		_energyPoints--;
	}
	else {
		cout << "ScavTrap " << getName() << " can't damage " << target
			<< ". Energy points left: " << _energyPoints
			<< ". Hit points left: " <<_hitPoints << endl;
	}
}