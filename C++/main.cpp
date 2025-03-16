#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// Helper function to trim whitespace from both ends of a string.
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

// Declaration for the user-defined solution function.
void solve();

int main(int argc, char* argv[]) {
    // If no arguments are given, run interactively using cin/cout.
    if (argc == 1) {
        solve();
    }
    // If three arguments are given, assume test mode:
    // argv[1] -> input file, argv[2] -> expected output file, argv[3] -> actual output file.
    else if (argc == 4) {
        ifstream inputFile(argv[1]);
        if (!inputFile) {
            cerr << "Error opening input file: " << argv[1] << "\n";
            return 1;
        }
        ofstream actualFile(argv[3]);
        if (!actualFile) {
            cerr << "Error opening actual output file: " << argv[3] << "\n";
            return 1;
        }
        
        // Save original stream buffers.
        streambuf* cinbuf = cin.rdbuf();
        streambuf* coutbuf = cout.rdbuf();
        
        // Redirect standard input and output.
        cin.rdbuf(inputFile.rdbuf());
        cout.rdbuf(actualFile.rdbuf());
        
        // Execute the user solution.
        solve();
        
        // Flush and close the output file (and input file) to ensure all output is written.
        cout.flush();
        actualFile.close();
        inputFile.close();
        
        // Restore original stream buffers.
        cin.rdbuf(cinbuf);
        cout.rdbuf(coutbuf);
        
        // Compare expected and actual output.
ifstream checkActual(argv[3]);
ifstream checkExpected(argv[2]);
string actualLine, expectedLine;
bool passed = true;

while(getline(checkExpected, expectedLine)) {
    if(!getline(checkActual, actualLine)) {
        cout << "Mismatch: Expected \"" << expectedLine << "\", but Your output ended early." << "\n";
        passed = false;
        break;
    }
    if(trim(actualLine) != trim(expectedLine)) {
        cout << "Mismatch found:" << "\n";
        cout << "Expected: \"" << expectedLine << "\"" << "\n";
        cout << "Your Ans  : \"" << actualLine << "\"" << "\n";
        passed = false;
        break;
    }
}
if(passed && getline(checkActual, actualLine)) { // Extra lines in actual output.
    cout << "Mismatch: Your output has extra line: \"" << actualLine << "\"" << "\n";
    passed = false;
}

cout << argv[1] << (passed ? " PASSED\n" : " FAILED\n");

       
    }
    // For any other usage, just run normally.
    else {
        solve();
    }
    return 0;
}
