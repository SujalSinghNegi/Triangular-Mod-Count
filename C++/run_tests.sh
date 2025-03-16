#!/bin/bash
# Compile the project automatically.
g++ main.cpp user_code.cpp -o solution

# For each input file (.in) in the current directory,
# run the solution with corresponding expected (.out) and actual (.actual) files.
for file in *.in; do
    base=$(basename "$file" .in)
    echo "Running test case: $file"
    if timeout 1s ./solution "$file" "${base}.out" "${base}.actual"; then
        echo "$file PASSED"
    else
        echo "$file TLE"
    fi
done
read -p "Press Enter to continue..."
