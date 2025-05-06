#include <iostream>
/*
lets you use:
- cin: input from keyboard
- cout: output from screen
- cerr: error messages
- endl: newline + flushing the output buffer
*/

#include <fstream>
/*
lets you use:
- ifstream: input file stream
- ofstream: output file stream
- fstream: file stream for both input and output
*/

#include <string>
/*
allows you to use the strings class
the string class allows you to use instances of strings
strings are like a list of chars
*/

#include <vector>
/*

*/

using namespace std;

int main() {

    string inputFile = "input.txt";
    ifstream file;

    file.open(inputFile);

    if (!file.is_open()) {
        cerr << "There was an error opening the file" << endl;
    }

    string line;
    while (getline(file, line)) {

    }

    file.close();

    return 0;
}