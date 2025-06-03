#include "../include/ClapTrap.hpp"
#include <cassert>

using std::cout;
using std::endl;

void attacking(
	ClapTrap& attacker
	, ClapTrap& target
	, const ClapTrap rsltA
	, const ClapTrap rsltB) 
{
		attacker.attack(target.getName());
		if (attacker.getHitPoints() > 0) {
			target.takeDamage(attacker.getAttackDamage());
		}
		else {
			cout << target.getName() << " not damaged!" << endl;
		}
		attacker.beRepaired(1);
		assert(attacker == rsltA);
		assert(target == rsltB);
}

int main() {
	ClapTrap a("Jim");
	ClapTrap b("Madonna");
	assert(a == ClapTrap("Jim", 10, 10, 0));
	assert(b == ClapTrap("Madonna", 10, 10, 0));
	attacking(a, b, ClapTrap("Jim", 11, 8, 0), ClapTrap("Madonna", 10, 10, 0));
	cout << endl;

	a.setAttackDamage(1);
	attacking(a, b, ClapTrap("Jim", 12, 6, 1), ClapTrap("Madonna", 9, 10, 0));
	cout << endl;

	a.setAttackDamage(8);
	attacking(a, b, ClapTrap("Jim", 13, 4, 9), ClapTrap("Madonna", 0, 10, 0));
	attacking(b, a, ClapTrap("Madonna", 1, 9, 0), ClapTrap("Jim", 13, 4, 9));
	cout << endl;
}
