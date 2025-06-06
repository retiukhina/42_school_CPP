#pragma once

#include <iostream>
#include <string>

using std::string;
using std:: cout;
using std:: endl;

class Animal {
	public:
		Animal();
		Animal(const string& animalType);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		string *str;

		void setType(const string& name);
		const string& getType() const;

		virtual void makeSound() const;

	protected:
		string _type;
};
