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

		virtual void makeSound() const;

		// functions to use the Brain
		virtual void setIdea(const string& keyword, const string& message);
		virtual string getIdea(const string& keyword) const;

	protected:
		string _type;
};
