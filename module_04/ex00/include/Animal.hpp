#pragma once

#include <iostream>
#include <string>

using std::string;
using std:: cout;
using std:: endl;

class Animal {
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		void setType(const string& name);

		virtual makeSound();

	protected:
		string type;
};
