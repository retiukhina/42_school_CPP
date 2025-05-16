#include "../include/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie *zmbHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zmbHorde[i].setName(name);
	}
	return zmbHorde;
}
