#include <iostream>
#include <vector>
#include <string>

using std::istream;
using std::vector;
using std::string;




// returns false if `s' is a lowercase letter and has neither any ascenders nor
// descenders, and true otherwise (thus the empty string returns true)

bool is_smallwd(const string& s) {

    string::const_iterator curr, end;
    char c;

    curr = s.begin();
    end = s.end();

    // each iteration checks if the current char is either an ascender or
    // descender, and returns false if so
    for ( ; curr != end; curr++) {
	
	c = *curr;
	
	if (!islower(c) ||
	    c == 'b' || c == 'd' || c == 'f' || c == 'h' || c == 'k' || c == 'l' || c == 't' ||
	    c == 'g' || c == 'j' || c == 'p' || c == 'q' || c == 'y') {

	    return false;
	}
    }

    // if we've made it here then there are no letters in `s' that are either
    // ascenders or descenders
    return true;
}




// read `in' and store each word without either ascenders or descenders from
// the stream into `small_words'.  The length of the longest word without either
// ascenders or descenders is stored in `maxlen'.  Any data that was stored in
// `small_words prior to being passed to the function is cleared, and if no word
// without either ascenders or descenders are found then `small_words' has an
// empty state and `maxlen' has value 0 after completion of the function.

istream& stream_ext_smallwd(istream& in, vector<string>& small_words, string::size_type& maxlen) {

    string curr;

    // assure we are starting form a clean slate
    small_words.clear();
    maxlen = 0;

    // each iteration reads one one from `in' and appends to the appropriate
    // vector
    while (in >> curr) {


	// case: word is without either ascenders or descenders.  Append current
	// word to `small_words'.
	if (is_smallwd(curr)) {
	    
	    small_words.push_back(curr);
	    if (curr.size() > maxlen) {
		maxlen = curr.size();
	    }
	}
    }

    return in;
}
