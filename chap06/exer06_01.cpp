// Page 122
//
// Reimplement the frame and hcat operations from sections 5.8.1 and 5.8.3
// (pages 93-94) to use iterators.

#include <iostream>
#include <vector>
#include <string>
#include "pics.h"

using std::cout;
using std::vector;
using std::string;


int main() {

    vector<string> input, out;
    
    input.push_back("this is an");
    input.push_back("example");
    input.push_back("to");
    input.push_back("illustrate");
    input.push_back("framing");

    out = hcat(input, frame(input));
    for (vector<string>::const_iterator curr = out.begin(); curr != out.end(); curr++) {
	cout << *curr << "\n";
    }

    return 0;
}
