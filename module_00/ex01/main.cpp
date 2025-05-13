#include "PhoneBook.hpp"

int main(){

	PhoneBook	phoneBook;
	std::string	input;

	while (true){
		std::cout << "Please choose your action. Type: ADD, SEARCH or EXIT: ";
		std::cout << std::endl;
		std::getline(std::cin, input);

		if (input == "ADD"){
			phoneBook.add();
		}
		else if (input == "SEARCH"){
			break;
		}
		else if (input == "EXIT"){
			break;
		}
		else{
			std::cout << "Uknown command" << std::endl;
		}
	}
}
