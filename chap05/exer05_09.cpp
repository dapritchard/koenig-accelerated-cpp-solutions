// Page 100
//
// Write a program to write the lowercase words in the input followed by the
// uppercase words.

#include <iostream>
#include <vector>
#include <string>
#include "stream_upp_seg.h"

using std::cin;
using std::cout;
using std::vector;
using std::string;


int main() {

    vector<string> lower, upper;
    stream_upp_seg(cin, lower, upper);

    // print lowercase words
    cout << "words with only lowercase letters:\n"
	 << "----------------------------------\n";
    for (vector<string>::const_iterator curr = lower.begin(); curr < lower.end(); curr++) {
	cout << *curr << "\n";
    }
    cout << "----------------------------------\n\n\n";

    // print words with an uppercase letter
    cout << "words with at least one uppercase letter:\n"
	 << "-----------------------------------------\n";
    for (vector<string>::const_iterator curr = upper.begin(); curr < upper.end(); curr++) {
	cout << *curr << "\n";
    }
    cout << "-----------------------------------------\n";

    return 0;
}
