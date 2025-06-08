#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

#include <cassert>

//#define TEST_ANIMAL
//#define TEST_BRAIN
#define TEST_ABSTRACT

int main() {
	#ifdef TEST_ANIMAL
	const Animal* meta = new Animal();
	const Animal* d = new Dog();

	assert(meta->getType() == "Animal");
	assert(d->getType() == "Dog");

	cout << d->getType() << " " << endl;
	d->makeSound();
	meta->makeSound();

	delete meta;
	delete d;
	#endif

	#ifdef TEST_BRAIN
	Cat cat;
	Animal* animal = &cat;
	cout << endl;
	animal->setIdea("food", "I'm hungry! Fish please!");
	cout<< animal->getIdea("food") << endl << endl;
	#endif

	#ifdef TEST_ABSTRACT
	Animal* a = new Cat();
	Animal* d = new Dog();
	cout << endl;
	a->makeSound();
	d->makeSound();
	cout << endl;
	a->setIdea("food", "I'm hungry! Fish please!");
	cout<< a->getIdea("food") << endl << endl;
	d->setIdea("play", "You wanna play? Pass me a ball!");
	cout<< d->getIdea("play") << endl;
	delete a;
	delete d;
	#endif
}
