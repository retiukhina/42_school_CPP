#include <iostream>
#include <string>

int main() {
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "The memory address of the string variable: " << &brain << std::endl;

	std::cout << "The memory address held by pointer to the string: " << stringPTR << std::endl;

	std::cout << "The memory address held by reference to the string: " << &stringREF << std::endl;

	std::cout << "The value of the string variable: " << brain << std::endl;

	std::cout << "The value pointed by pointer: " << *stringPTR << std::endl;

	std::cout << "The value pointed to by reference: " << stringREF << std::endl;
}
