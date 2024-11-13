#!/bin/bash

# Compile the code with g++
g++ -std=c++17 -g -Wall -Wextra -pedantic-errors -Weffc++ -Wno-unused-parameter -fsanitize=undefined,address RoverTest.cpp Rover.cpp MyString.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful."
    
    # Prompt the user for the input file
    read -p "Enter the input file name (e.g., commands1.txt): " input_file
    
    # Check if the file exists
    if [ -f "$input_file" ]; then
        echo "Running the program with input from $input_file..."
        ./a.out < "$input_file" # Run the program with the specified input file
    else
        echo "Error: File '$input_file' not found."
    fi
else
    echo "Compilation failed."
fi
