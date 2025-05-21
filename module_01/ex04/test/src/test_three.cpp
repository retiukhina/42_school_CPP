#include "../include/test_sed.hpp"

void test_three(const std::string& inputFile, const std::string& s1,
                const std::string& s2, const std::string& expectedOutput)
{
    // Write test input to input file
    std::ofstream input(inputFile.c_str());
    assert(input && "Failed to open input file");
    input << "The parameters determine how many elements are inserted.";
    input.close();

    std::string errorFile = inputFile + ".replace";
    std::string cmd = "../sed \"" + inputFile + "\" \"" + s1 + "\" \"" + s2 + "\" 2> " + errorFile;

    int result = std::system(cmd.c_str());
    assert(result != 0 && "Program was expected to fail but didn't");

    // Read the error message from stderr (redirected to file)
    std::ifstream output(errorFile.c_str());
    assert(output && "Failed to open error file");

    std::string content;
    std::getline(output, content, '\0');
    output.close();

    std::cout << "Test 3: " << content << std::endl;

    assert(content == expectedOutput && "Test failed: error message doesn't match expected.");
    std::cout << "Test passed" << std::endl;
}

