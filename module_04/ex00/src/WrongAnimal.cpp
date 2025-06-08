#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: _type("WrongAnimal")
{
	cout << "WrongAnimal called defualt constructor" << endl;
}

WrongAnimal::WrongAnimal(const string& WrongAnimalType)
	: _type(WrongAnimalType)
{
	cout << "WrongAnimal called constructor by name" << endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
	cout << "WrongAnimal called copy constructor" << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		_type = other._type;
	}
	cout << "WrongAnimal call assignment operator" << endl;
	return *this;
}

void WrongAnimal::setType(const string& name) {
	this->_type = name;
}

const string& WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	cout << "Make function makeSound() and destructor in WrongAnimal class virtual: WrongCats have something to say!" << endl;
}

WrongAnimal::~WrongAnimal() {
	cout << "WrongAnimal called destructor" << endl;
}
