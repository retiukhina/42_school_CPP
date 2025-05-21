#!/bin/bash

# Build the program
c++ -Wall -Wextra -Werror -std=c++98 main.cpp ../src/Harl.cpp -o harl

# Run the program (generates output.txt)
./harl

# Compare with expected.txt
if diff -q expected.txt output.txt > /dev/null; then
    echo "✅ Test passed: Output matches expected"
else
    echo "❌ Test failed: Output differs from expected"
    echo "----- diff output -----"
    diff expected.txt output.txt
fi

rm output.txt ./harl
