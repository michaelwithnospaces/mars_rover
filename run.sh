#!/bin/bash

# Compile the code with g++
g++ -std=c++17 -g -Wall -Wextra -pedantic-errors -Weffc++ -Wno-unused-parameter -fsanitize=undefined,address RoverTest.cpp Rover.cpp MyString.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful."
    ./a.out
else
    echo "Compilation failed."
fi
