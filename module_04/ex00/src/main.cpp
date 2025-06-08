#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

#include <cassert>

int main() {
	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	const WrongAnimal *alpha = new WrongAnimal();
	const WrongAnimal *wc = new WrongCat();

	assert(meta->getType() == "Animal");
	assert(d->getType() == "Dog");
	assert(c->getType() == "Cat");
	assert(wc->getType() == "WrongCat");

	cout << d->getType() << " " << endl;
	cout << c->getType() << " " << endl;
	cout << wc->getType() << " " << endl;
	c->makeSound(); //will output the cat sound!
	d->makeSound();
	meta->makeSound();
	alpha->makeSound();
	wc->makeSound();
}
