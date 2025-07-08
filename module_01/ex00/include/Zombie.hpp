#pragma once

#include <string>
#include <iostream>

class Zombie {
	public:
		//constructor
		Zombie(std::string name);

		void announce(void);

		// Destructor
		~Zombie();

	private:
		std::string _name;
};
