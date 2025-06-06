#include "../include/Cat.hpp"

Cat::Cat() 
    : Animal("Cat")
{
    cout << "Cat called default constructor" << endl;
}

Cat::Cat(const string& animalType)
    : Animal(animalType)
{
    cout << "Cat called constructor by name" << endl;
}

Cat::Cat(const Cat& other)
    : Animal(other)
{
    cout << "Cat called copy constructor" << endl;
}
		
Cat& Cat::operator=(const Cat& other) 
    {
    if (this != &other) {
        Animal::operator=(other);
    }
    cout << "Cat called copy assignment operator" << endl;
    return (*this);
}

void Cat::makeSound() const {
    cout << "Cat says: Meow... Murr... Murr..." << endl;
}

Cat::~Cat() {
    cout << "Cat called destructor" << endl;
}