#pragma once

#include <iostream>
#include <string>

using std::string;
using std:: cout;
using std:: endl;

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const string& animalType);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal();

		void setType(const string& name);
		const string& getType() const;

		void makeSound() const;

	protected:
		string _type;
};
