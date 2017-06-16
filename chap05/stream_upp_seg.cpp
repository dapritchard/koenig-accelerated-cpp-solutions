#include <iostream>
#include <vector>
#include <string>

using std::istream;
using std::vector;
using std::string;




// return true if any char in `s' is uppercase, and return false otherwise

bool has_upper(string s) {

    string::const_iterator end = s.end();

    // step through the chars in `s' and return true if an uppercase char is
    // found
    for (string::const_iterator curr = s.begin(); curr != end; curr++) {
	if (isupper(*curr)) {
	    return true;
	}
    }

    // if we've made it here then no uppercase char was found
    return false;
}




// read data from `in' and tokenize into words.  Words that do not contain any
// uppercase letters are appended to `lower', and words with at least one
// uppercase letter are appended to `upper'.  The words are appended in the same
// order in which they are read from `in'.

istream& stream_upp_seg(istream& in, vector<string>& lower, vector<string>& upper) {

    string curr;
    
    while (in >> curr) {

	// 
	if (has_upper(curr)) {
	    upper.push_back(curr);
	} else {
	    lower.push_back(curr);
	}
    }

    return in;
}
