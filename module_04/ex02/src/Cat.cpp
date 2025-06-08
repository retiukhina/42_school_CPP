#include "../include/Cat.hpp"

Cat::Cat()
	: Animal("Cat")
	, _brain(new Brain())
{
	cout << "Cat called default constructor" << endl;
}

Cat::Cat(const string& animalType, const Brain& brain)
	: Animal(animalType)
	, _brain(new Brain(brain))
{
	cout << "Cat called constructor by name" << endl;
}

Cat::Cat(const Cat& other)
	: Animal(other)
	, _brain(new Brain(*other._brain)) // deep copy
{
	cout << "Cat called copy constructor" << endl;
}

Cat& Cat::operator=(const Cat& other)
	{
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	cout << "Cat called copy assignment operator" << endl;
	return (*this);
}

void Cat::makeSound() const {
	cout << "Cat says: Meow... Murr... Murr..." << endl;
}

void Cat::setIdea(const std::string& keyword, const std::string& message) {
	_brain->setIdea(keyword, message);
}

string Cat::getIdea(const std::string& keyword) const {
	return _brain->getIdea(keyword);
}

Cat::~Cat() {
	delete _brain;
	cout << "Cat called destructor" << endl;
}
