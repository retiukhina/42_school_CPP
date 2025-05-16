#include "../include/Zombie.hpp"
#include "../include/Zombie.h"

int main() {

	// dynamic zombie
	Zombie *zheap = newZombie("Boo");
	zheap->announce();
	delete zheap;

	// static zombie
	std::string name = "Foo";
	randomChump(name);
	return 0;
}
