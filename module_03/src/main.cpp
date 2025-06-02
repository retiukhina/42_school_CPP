#include "../include/ClapTrap.hpp"
#include <cassert>

using std::cout;
using std::endl;

void attacking(ClapTrap& attacker, const string& target, int n) {
	while(n > 0) {
		attacker.attack(target);
		attacker.takeDamage(attacker.getAttackDamage());
		attacker.beRepaired(1);
		n--;
	}
}

int main() {
	ClapTrap a("Jim");
	ClapTrap b("Madonna");
	assert(a == ClapTrap("Jim", 10, 10, 0));
	assert(b == ClapTrap("Madonna", 10, 10, 0));
	attacking(a, "Bob", 4);
	attacking(b, "Selina", 3);
}
