#pragma once

#include <string>

class Weapon {
	public:
		Weapon(const std::string& Value);
		const std::string& getType() const;
		void setType(const std::string& newValue);

	private:
		std::string type;
};
