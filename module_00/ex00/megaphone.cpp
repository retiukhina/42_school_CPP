#include <iostream>
#include <ctype.h>
#include <string.h>

std::string stringToUpper(std::string &inputString){

	std::string conevrtedString;

	for (std::size_t i = 0; i < inputString.length(); ++i){
			conevrtedString += std::toupper(static_cast<unsigned char>(inputString[i]));
		}
	return conevrtedString;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else {
		for (int i = 1; i < argc; ++i) {
			std::string str(argv[i]);
			std::cout << stringToUpper(str);
		}
	}
	std::cout << std::endl;
	return 0;
}
