#!/bin/bash
# Compile the Java solution.
javac Main.java UserCode.java

# Loop over all .in files (sorted alphabetically).
for file in *.in; do
    base=$(basename "$file" .in)
    echo "Running test case: $file"
    timeout 10s java Main < "$file" > "${base}.actual"
    if [ $? -eq 124 ]; then
        echo "$file TLE"
    else
        echo "$file Completed"
    fi
done
