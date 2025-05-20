#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

static const size_t MAX_INPUT_LENGTH = 256;

bool openFiles(std::ifstream& input, std::ofstream& output);
bool openReadFile(std::ifstream& input, const std::string& filename);
bool openWriteFile(std::ofstream& output, const std::string& filename);
bool readUserInput(std::string& s1, std::string& s2);
bool validateInput(const std::string& s, const char* name);
bool findAndReplace(std::string& s, const std::string s1, const std::string s2);
