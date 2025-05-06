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

#include <sstream>
/*
lets you use:
- stringstream ss(inputfile): takes inputfile as an input
*/
#include <string>
/*
allows you to use the strings class
the string class allows you to use instances of strings
strings are like a list of chars
*/

#include <vector>
/*
allows you to use the vector class
common methods:
- push_back(x): adds x to the end
- size(): returns number of elements
- empty(): returns true if vector is empty
- clear(): Removes all elements
- erase(pos): removes elements at pos
- at(i): returns element at i
*/

using namespace std;

vector<int> sort(const vector<int> list) {
    vector<int> slist;

    if (list.size() == 0) {
        return slist;
    }

    for (int i = 0; i < list.size(); ++i) {
        int a = list.at(i);

        if (slist.size() == 0) {
            slist.push_back(a);
        } else {
            bool inserted = false;
            for (int j = 0; j < slist.size(); ++j) {
                int b = slist.at(j);

                if (a < b) {
                    slist.insert(slist.begin()+ j, a);
                    inserted = true;
                    break;
                }
            }

            if (!inserted) {
                slist.push_back(a);
            }
        }

    }

    return slist;
}

int main() {

    string inputFile = "input.txt";
    ifstream file;

    vector<int> llist, rlist;

    file.open(inputFile);

    if (!file.is_open()) {
        cerr << "There was an error opening the file" << endl;
    }

    string line;
    while (getline(file, line)) {
        int lnum, rnum;
        stringstream ss(line);

        ss >> lnum >> rnum;
        
        llist.push_back(lnum);
        rlist.push_back(rnum);
    }

    file.close();

    vector<int> orderedLeftList = sort(llist);
    vector<int> orderedRightList = sort(rlist);

    int diff = 0;
    for (int i = 0; i < orderedLeftList.size(); ++i) {
        diff = diff + abs(orderedLeftList.at(i) - orderedRightList.at(i));
    }
    
    cout << diff << endl;

    return 0;
}