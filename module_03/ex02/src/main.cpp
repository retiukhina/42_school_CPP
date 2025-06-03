#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

#include <cassert>

using std::cout;
using std::endl;

void ScavAgainstFrag(
	ScavTrap& attacker
	, FragTrap& target
	, const ScavTrap rsltA
	, const FragTrap rsltB
){
	attacker.attack(target.getName());
	if (attacker.getHitPoints() > 0) {
		target.takeDamage(attacker.getAttackDamage());
	}
	else {
		target.highFivesGuys();
	}
	attacker.beRepaired(1);
	assert(attacker == rsltA);
	assert(target == rsltB);
	cout << endl;
}

void ClapAgainstFrag(
	ClapTrap& attacker
	, FragTrap& target
	, const ClapTrap rsltA
	, const FragTrap rsltB
){
		attacker.attack(target.getName());
		if (attacker.getHitPoints() > 0) {
			target.takeDamage(attacker.getAttackDamage());
		}
		else {
			target.highFivesGuys();
		}
		attacker.beRepaired(1);
		assert(attacker == rsltA);
		assert(target == rsltB);
		cout << endl;
}

int main() {
	ClapTrap a("Jim");
	ScavTrap c("Nick", 0, 50, 20);
	FragTrap b("Madonna");
	assert(a == ClapTrap("Jim", 10, 10, 0));
	assert(c == ScavTrap("Nick", 0, 50, 20));
	assert(b == FragTrap("Madonna", 100, 100, 30));
	cout << "\033[1;32m\nClapTrap against FragTrap:\033[0m" << endl;
	ClapAgainstFrag(a, b, ClapTrap("Jim", 11, 8, 0), FragTrap("Madonna", 100, 100, 30));
	cout << "\033[1;32m\nScavTrap against FragTrap:\033[0m" << endl;
	ScavAgainstFrag(c, b, ScavTrap("Nick", 1, 49, 20), FragTrap("Madonna", 100, 100, 30));
	cout << "\033[1;32m\nScavTrap repaired and fight against FragTrap again!\033[0m" << endl;
	ScavAgainstFrag(c, b, ScavTrap("Nick", 2, 47, 20), FragTrap("Madonna", 80, 100, 30));
}
