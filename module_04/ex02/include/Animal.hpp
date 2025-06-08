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

		void setType(const string& name);
		const string& getType() const;

		// pure virtual functions
		virtual void makeSound() const = 0;

		// pure virtual functions to use the Brain
		virtual void setIdea(const string& keyword, const string& message) = 0;
		virtual string getIdea(const string& keyword) const = 0;

	protected:
		string _type;
};
