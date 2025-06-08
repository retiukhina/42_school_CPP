#include "../include/Dog.hpp"

Dog::Dog()
	: Animal("Dog")
{
	_brain = new Brain();
	cout << "Dog called default constructor" << endl;
}

Dog::Dog(const string& animalType)
	: Animal(animalType)
{
	cout << "Dog called constructor by name" << endl;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	_brain = new Brain(*other._brain); // deep copy
	cout << "Dog called copy constructor" << endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	cout << "Dog called copy assignment operator" << endl;
	return (*this);
}

void Dog::makeSound() const {
	cout << "Dog says: Wuff! Wuff! Ruff!" << endl;
}

void Dog::setIdea(const std::string& keyword, const std::string& message) {
	_brain->setIdea(keyword, message);
}

std::string Dog::getIdea(const std::string& keyword) const {
	return _brain->getIdea(keyword);
}


Dog::~Dog() {
	delete _brain;
	cout << "Dog called destructor" << endl;
}
