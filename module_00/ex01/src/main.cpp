#include "../include/PhoneBook.hpp"

int main() {
	PhoneBook	pb;
	std::string	input;

	while (true){
		std::cout << "Please choose your action. Type: ADD, SEARCH or EXIT: ";
		std::cout << std::endl;
		std::getline(std::cin, input);

		if (input == "ADD"){
			pb.add();
		}
		else if (input == "SEARCH"){
			if (!pb.search())
				break;
		}
		else if (input == "EXIT"){
			break;
		}
		else{
			std::cout << "Uknown command. Type: ADD, SEARCH or EXIT: " << std::endl;
		}
	}
}
