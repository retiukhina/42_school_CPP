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
	attacking(a, b, ScavTrap("Jim", 102, 46, 20), ScavTrap("Madonna", 60, 50, 20));
	cout << endl;
	ScavTrap c("Nick", 0, 0, 20);
	attacking(c, a, ScavTrap("Nick", 0, 0, 20), ScavTrap("Jim", 102, 46, 20));
	// attacking(a, b, ScavTrap("Jim", 13, 4, 9), ScavTrap("Madonna", 0, 10, 0));
	// attacking(b, a, ScavTrap("Madonna", 1, 9, 0), ScavTrap("Jim", 13, 4, 9));
	// cout << endl;
}
