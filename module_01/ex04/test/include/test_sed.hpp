#include "../../include/sed.hpp"
#include <cassert>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

void test_one(const std::string& inputFile, const std::string& s1,
               const std::string& s2, const std::string& expectedOutput);

void test_two(const std::string& inputFile, const std::string& s1,
               const std::string& s2, const std::string& expectedOutput);

void test_three(const std::string& inputFile, const std::string& s1,
               const std::string& s2, const std::string& expectedOutput);
