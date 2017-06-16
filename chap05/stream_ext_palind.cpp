#include <iostream>
#include <vector>
#include <string>

using std::istream;
using std::vector;
using std::string;




// returns false if `s' is not a palindrome, and true otherwise (thus the empty
// string returns true)

bool is_palindrome(const string& s) {

    string::const_iterator forward, reverse;

    forward = s.begin();
    reverse = s.end();

    // each iteration checks the k-th char from the with the k-th char from the
    // right.  If any are not equal then return false
    while (forward < reverse) {

	// the reverse iterator starts one past the last element, so decrement
	// this before making comparisons
	reverse--;

	// want palindromes to be case-insensitive so convert to lowercase
	// before comparing equality
	if (tolower(*forward) != tolower(*reverse)) {
	    return false;
	}

	forward++;
    }

    // if we've made it here then each char from left-to-right matched all the
    // chars from right-to-left
    return true;
}




// read `in' and store each word that is a palindrome from the stream into
// `palindromes'.  The length of the longest palindrome is stored in `maxlen'.
// Any data that was stored in `palindromes prior to being passed to the
// function is cleared, and if no palindromes are found then `palindrome' has an
// empty state and `maxlen' has value 0 after completion of the function.

istream& stream_ext_palind(istream& in, vector<string>& palindromes, string::size_type& maxlen) {

    string curr;

    // assure we are starting form a clean slate
    palindromes.clear();
    maxlen = 0;

    // each iteration reads one one from `in' and appends to the appropriate
    // vector
    while (in >> curr) {

	// case: a palindrome.  Append current word to `palindrome'.
	if (is_palindrome(curr)) {
	    
	    palindromes.push_back(curr);
	    if (curr.size() > maxlen) {
		maxlen = curr.size();
	    }
	}
    }

    return in;
}
