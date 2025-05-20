#pragma once

#include <string>
#include <iostream>
#include "HarlMessages.hpp"

class Harl {
	public:
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};
