#include "../include/Dog.hpp"

Dog::Dog() 
    : Animal("Dog")
{
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
    cout << "Dog called copy constructor" << endl;
}
		
Dog& Dog::operator=(const Dog& other) 
    {
    if (this != &other) {
        Animal::operator=(other);
    }
    cout << "Dog called copy assignment operator" << endl;
    return (*this);
}

void Dog::makeSound() const {
    cout << "Dog says: Wuff! Wuff! Ruff!" << endl;
}

Dog::~Dog() {
    cout << "Dog called destructor" << endl;
}