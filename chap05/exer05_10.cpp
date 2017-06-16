// Page 100
//
// Palindromes are words that are spelled the same right to left as left to
// right.  Write a program to find all the palindromes in a dictionary. Next,
// find the longest palindrome.

#include <iostream>
#include <vector>
#include <string>
#include "stream_ext_palind.h"

using std::cin;
using std::cout;
using std::vector;
using std::string;


int main() {

    vector<string> palindromes;
    string::size_type maxlen;
    stream_ext_palind(cin, palindromes, maxlen);

    // print palindroms
    cout << "palindromes:\n"
	 << "----------------------------------\n";
    for (vector<string>::const_iterator curr = palindromes.begin();
	 curr < palindromes.end(); curr++) {
	
	cout << *curr << "\n";
    }
    cout << "----------------------------------\n"
	 << "maximum word length:  " << maxlen << "\n";

    return 0;
}
