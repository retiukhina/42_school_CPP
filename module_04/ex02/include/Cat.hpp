#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const string& animalType, const Brain& brain);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void setIdea(const std::string& keyword, const std::string& message);
		string getIdea(const std::string& keyword) const;

		void makeSound() const;
};
