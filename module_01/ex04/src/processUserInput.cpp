#include "../include/sed.hpp"

// Sanitize and validate input strings s1 and s2
bool validateInput(const std::string& s, const char* name) {
    if (s.empty()) {
        std::cerr << "Input string " << name << " cannot be empty." << std::endl;
        return false;
    }
    if (s.size() > MAX_INPUT_LENGTH) {
        std::cerr << "Input string " << name << " is too long (max " << MAX_INPUT_LENGTH << " characters)." << std::endl;
        return false;
    }
    return true;
}

bool readUserInput(std::string& s1, std::string& s2) {
    std::cout << "Enter search string: ";
    if (!std::getline(std::cin, s1)) {
        std::cerr << "Failed to read s1." << std::endl;
        return false;
    }

    std::cout << "Enter replacement string: ";
    if (!std::getline(std::cin, s2)) {
        std::cerr << "Failed to read s2." << std::endl;
        return false;
    }
    return true;
}
