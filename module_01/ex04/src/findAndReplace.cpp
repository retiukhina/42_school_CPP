#include "../include/sed.hpp"

bool findAndReplace(std::string& s, const std::string s1, const std::string s2) {
    if (s.empty()) {
        std::cerr << "Error: Search string is empty.";
        return false;
    }

    std::string::size_type pos = 0;
    while((pos = s.find(s1, pos)) != std::string::npos)
    {
        //replaces
        s.erase(pos, s1.length());
        s.insert(pos, s2);
        pos += s2.length();
    }
    return true;
}
