// Reimplement the gen_sentence program using two vector s: One will hold the
// fully unwound, generated sentence, and the other will hold the rules and will
// be used as a stack.  Do not use any recursive calls.

#include <iostream>
#include <string>
#include <vector>
#include "gen_sentence.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;


int main() {
    
    // generate the sentence
    vector<string> sentence = gen_sentence(read_grammar(cin));

    // write the first word, if any
    vector<string>::const_iterator it = sentence.begin();
    if (! sentence.empty()) {
	cout << *it;
	++it;
    }

    // write the rest of the words, each preceded by a space
    for ( ; it != sentence.end(); it++) {
	cout << " " << *it;
    }
    cout << "\n";
    
    return 0;
}
