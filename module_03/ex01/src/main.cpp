#include "../include/ScavTrap.hpp"
#include <cassert>

using std::cout;
using std::endl;

void attacking(
	ScavTrap& attacker
	, ScavTrap& target
	, const ScavTrap rsltA
	, const ScavTrap rsltB)
{
		attacker.attack(target.getName());
		if (attacker.getHitPoints() > 0) {
			target.takeDamage(attacker.getAttackDamage());
		}
		else {
			target.guardGate();
		}
		attacker.beRepaired(1);
		assert(attacker == rsltA);
		assert(target == rsltB);
}

int main() {
	ScavTrap a("Jim");
	ScavTrap b("Madonna");
	assert(a == ScavTrap("Jim", 100, 50, 20));
	assert(b == ScavTrap("Madonna", 100, 50, 20));
	attacking(a, b, ScavTrap("Jim", 101, 48, 20), ScavTrap("Madonna", 80, 50, 20));
	cout << endl;

	// a.setAttackDamage(1);
	// attacking(a, b, ScavTrap("Jim", 12, 6, 1), ScavTrap("Madonna", 9, 10, 0));
	// cout << endl;

	// a.setAttackDamage(8);
	// attacking(a, b, ScavTrap("Jim", 13, 4, 9), ScavTrap("Madonna", 0, 10, 0));
	// attacking(b, a, ScavTrap("Madonna", 1, 9, 0), ScavTrap("Jim", 13, 4, 9));
	// cout << endl;
}
