#include "../include/sed.hpp"

int main() {
    std::string s1, s2;

	if (!readUserInput(s1, s2)) {
		return 1;
	}

	std::ifstream input;
	std::ofstream output;

	// Open files
	if (!openFiles(input, output)) {
		return 1;
	}
	// Validate inputs
    if (!validateInput(s1, "s1") || !validateInput(s2, "s2")) {
        return 1;
    }
    std::string line;
    while (std::getline(input, line)) {
		if (!findAndReplace(line, s1, s2)) {

			break;
		}
        output << line << std::endl;
        if (!output) {  // Check output stream for errors (disk full, etc)
            std::cerr << "Error writing to output file." << std::endl;
            return 1;
        }
    }
	if (!input.eof()) {
        // Something went wrong reading file (e.g., disk error)
        std::cerr << "Error reading input file." << std::endl;
        return 1;
    }
    input.close();
    output.close();
	std::cout << "File processed successfully." << std::endl;
    return 0;
}
