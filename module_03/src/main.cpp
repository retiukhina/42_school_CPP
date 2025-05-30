#include "../include/ClapTrap.hpp"

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
	ClapTrap c("Karl", 15, 7, 8);
	attacking(a, "Bob", 4);
	attacking(b, "Selina", 3);
	attacking(c, "Max", 17);
}
