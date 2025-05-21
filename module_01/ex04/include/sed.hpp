#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

static const size_t MAX_INPUT_LENGTH = 256;

bool openFiles(const std::string inputFilename, std::ifstream& input,
    std::ofstream& output);
bool openReadFile(std::ifstream& input, const std::string& filename);
bool openWriteFile(std::ofstream& output, const std::string& filename);
bool validateInput(const std::string& s);
bool findAndReplace(std::string& s, const std::string s1, const std::string s2);
