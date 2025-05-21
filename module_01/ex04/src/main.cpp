#include "../include/sed.hpp"

int main(int argc, char* argv[]) {
	if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

	std::ifstream input;
	std::ofstream output;

	// Open files
	if (!openFiles(filename, input, output)) {
		return 1;
	}
	// Validate inputs
    if (!validateInput(s1) || !validateInput(s2)) {
        return 1;
    }
    std::string line;
    while (std::getline(input, line)) {
		if (!findAndReplace(line, s1, s2)) {

			break;
		}
        output << line;
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
	std::cout << "File processed successfully.";
	std::cout << std::endl;
    return 0;
}
