#include "../include/sed.hpp"

// Sanitize and validate input strings s1 and s2
bool validateInput(const std::string& s) {
    if (s.empty()) {
        std::cerr << "Input string cannot be empty.";
        return false;
    }
    if (s.size() > MAX_INPUT_LENGTH) {
        std::cerr << "Input string is too long (max " << MAX_INPUT_LENGTH << " characters).";
        return false;
    }
    return true;
}
