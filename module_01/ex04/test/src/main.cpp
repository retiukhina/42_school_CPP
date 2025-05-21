#include "../include/test_sed.hpp"
#include <cassert>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

int main() {
    test_one("test1.txt", "hello", "hi", "hi world, hi user.");
	test_two("test2.txt", "inserted", "replaced", "The parameters determine how many elements are replaced.");
	test_three("test3.txt", "", "", "Input string cannot be empty.");
}
