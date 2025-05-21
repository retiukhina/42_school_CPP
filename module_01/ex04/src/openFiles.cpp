#include "../include/sed.hpp"

bool openWriteFile(std::ofstream& output, const std::string& filename) {
    output.open (filename.c_str(), std::ios::out | std::ios::trunc); // open file for writing

    if (!output) {
        std::cerr << "Failed to open second file." << std::endl;
        return false;
    }
	return true;
}

bool openReadFile(std::ifstream& input, const std::string& filename)
{
    input.open(filename.c_str(), std::ios::in); // open file for reading

    if (!input) {
        std::cerr << "Failed to open first file." << std::endl;
        return false;
    }
	return true;
}

bool openFiles(const std::string inputFilename, std::ifstream& input,
    std::ofstream& output)
{
    const std::string outputFilename = inputFilename + ".replace";

    if (!openReadFile(input, inputFilename)) {
		return false;
	}
    if (!openWriteFile(output, outputFilename)) {
        input.close();
        return false;
    }
    return true;
}
