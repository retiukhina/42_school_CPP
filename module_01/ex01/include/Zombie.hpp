#pragma once

#include <string>
#include <iostream>
#include <new>

class Zombie {
	public:
		//constructor
		Zombie();

		void setName(std::string s);
		void announce(void);

		// Destructor
		~Zombie();

	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);
