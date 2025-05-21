#include "../include/Harl.hpp"
#include <iostream>
#include <fstream>

int main() {
    Harl harl;
	// Open (or creates) the file output.txt for writing
    std::ofstream out("output.txt");

	// Return a pointer to the current output buffer of std::cout
    std::streambuf* originalCout = std::cout.rdbuf();
	// Redirect std::cout to use the buffer of out instead of terminal
    std::cout.rdbuf(out.rdbuf());

    std::cout << "=== DEBUG ===" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "=== INFO ===" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "=== WARNING ===" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "=== ERROR ===" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "=== INVALID ===" << std::endl;
    harl.complain("RANDOM");
    std::cout << std::endl;

    std::cout << "=== LOWERCASE DEBUG ===" << std::endl;
    harl.complain("debug");

	// Put cout back to terminal
    std::cout.rdbuf(originalCout); // Restore original cout

    out.close();
    return 0;
}
