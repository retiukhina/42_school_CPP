#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

#include <cassert>

int main() {
    const Animal* meta = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    assert(meta->getType() == "Animal");
    assert(d->getType() == "Dog");
    assert(c->getType() == "Cat");
    
    cout << d->getType() << " " << endl;
    cout << c->getType() << " " << std::endl;
    c->makeSound(); //will output the cat sound!
    d->makeSound();
    meta->makeSound();
}