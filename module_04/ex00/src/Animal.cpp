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

void Animal::setType(const string& name) {
	this->_type = name;
}

const string& Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	cout << "Animals make different sounds" << endl;
}

Animal::~Animal() {
	cout << "Animal called destructor" << endl;
}

