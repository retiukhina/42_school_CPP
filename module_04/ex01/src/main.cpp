#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

#include <cassert>

#define TEST_ANIMAL
#define TEST_BRAIN

int main() {
	#ifdef TEST_ANIMAL
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

	delete meta;
	delete d;
	delete c;
	delete alpha;
	delete wc;
	#endif

	#ifdef TEST_BRAIN
	Cat cat;
	Animal* animal = &cat;
	cout << endl;
	animal->setIdea("food", "I'm hungry! Fish please!");
	cout<< animal->getIdea("food") << endl << endl;

	Dog dog;
	Animal *animal2 = &dog;
	cout << endl;
	animal2->setIdea("play", "You wanna play? Pass me a ball!");
	cout<< animal2->getIdea("play") << endl << endl;
	#endif
}
