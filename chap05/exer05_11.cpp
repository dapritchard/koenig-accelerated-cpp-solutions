// Page 100
//
// In text processing it is sometimes useful to know whether a word has any
// ascenders or descenders.  Ascenders are the parts of lowercase letters that
// extend above the text line; in the English alphabet, the letters b, d, f, h,
// k, l, and t have ascenders.  Similarly, the descenders are the parts of
// lowercase letters that descend below the line; In English, the letters g, j,
// p, q, and y have descenders.  Write a program to determine whether a word has
// any ascenders or descenders.  Extend that program to find the longest word in
// the dictionary that has neither ascenders nor descenders
    

#include <iostream>
#include <vector>
#include <string>
#include "stream_ext_smallwd.h"

using std::cin;
using std::cout;
using std::vector;
using std::string;


int main() {

    vector<string> small_words;
    string::size_type maxlen;
    stream_ext_smallwd(cin, small_words, maxlen);

    // print words without either ascenders or descenders
    cout << "words without either ascenders or descenders:\n"
	 << "----------------------------------\n";
    for (vector<string>::const_iterator curr = small_words.begin();
	 curr < small_words.end(); curr++) {
	
	cout << *curr << "\n";
    }
    cout << "----------------------------------\n"
	 << "maximum word length:  " << maxlen << "\n";

    return 0;
}
