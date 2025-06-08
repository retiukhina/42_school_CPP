#include "../include/Animal.hpp"

Animal::Animal()
	: _type("Animal")
{
	cout << "Animal called defualt constructor" << endl;
}

Animal::Animal(const string& animalType)
	: _type(animalType)
{
	cout << "Animal called constructor by name" << endl;
}

// Copy constructor
Animal::Animal(const Animal& other) {
	*this = other;
	cout << "Animal called copy constructor" << endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
	}
	cout << "Animal call assignment operator" << endl;
	return *this;
}

void Animal::setIdea(const string& keyword, const string& message) {
	(void)keyword;
	(void)message;
	cout << "Animals have no ideas." << endl;
}

string Animal::getIdea(const std::string& keyword) const {
	(void)keyword;
	return "No idea found in base Animal";
}

Animal::~Animal() {
	cout << "Animal called destructor" << endl;
}

