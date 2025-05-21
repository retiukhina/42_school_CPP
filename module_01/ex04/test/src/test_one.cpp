#include "../include/test_sed.hpp"

void test_one(const std::string& inputFile, const std::string& s1,
               const std::string& s2, const std::string& expectedOutput)
{
	// Write test input to input file
	std::ofstream input(inputFile.c_str());
	assert(input && "Failed to open input file");
	input << "hello world, hello user.";
	input.close();

	// Build an executable
	std::string cmd = "../sed " + inputFile + " " + s1 + " " + s2;
	// Run that executable
	int result = std::system(cmd.c_str());
	assert(result == 0 && "Program execution failed");

	// Read and veify output
	std::ifstream output((inputFile + ".replace").c_str());
	assert(output && "Failed to open out[ut file");

	std::string content;
	std::getline(output, content, '\0');
	std::cout << "Test 1: " << content << std::endl;
	output.close();

	assert(content == expectedOutput && "Test failed: output doesn't match expected.");
	std::cout << "Test passed" << std::endl;
}
