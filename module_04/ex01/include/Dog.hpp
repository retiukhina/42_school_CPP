#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain* _brain;

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		Dog(const string& animalType);
		~Dog();

		void setIdea(const std::string& keyword, const std::string& message);
		string getIdea(const std::string& keyword) const;

		void makeSound() const;
};
