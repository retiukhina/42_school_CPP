#include "../include/WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal("WrongCat")
{
    cout << "WrongCat called default constructor" << endl;
}

WrongCat::WrongCat(const string& WrongAnimalType)
    : WrongAnimal(WrongAnimalType)
{
    cout << "WrongCat called constructor by name" << endl;
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other)
{
    cout << "WrongCat called copy constructor" << endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
    {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    cout << "WrongCat called copy assignment operator" << endl;
    return (*this);
}

void WrongCat::makeSound() const {
    cout << "WrongCat says: Piu... Piu... Piu..." << endl;
}

WrongCat::~WrongCat() {
    cout << "WrongCat called destructor" << endl;
}
