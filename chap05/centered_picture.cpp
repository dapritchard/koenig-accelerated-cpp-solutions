#include <vector>
#include <string>

using std::vector;
using std::string;


// return a vector of strings such so that when the vector is printed in order
// and with each string separated by a newline, it centers and frames the
// strings provided by words.  The frame is constructed with asterisks and has
// one char of horizontal padding on each side and no chars of vertical padding.
// Centering is performed so that when there is an odd number of blanks that
// need to be added the right side gets one more blank than the left.

vector<string> center(const vector<string>& words) {

    vector<string> centered;

    // find the longest word in `words'
    string::size_type maxlen = 0;
    for (vector<string>::const_iterator curr = words.begin(); curr != words.end(); curr++) {
    	if (curr->size() > maxlen) {
    	    maxlen = curr->size();
    	}
    }

    // add top of picture frame
    centered.push_back(string(maxlen + 4, '*'));

    // each iteration appends one line of the centered and framed image to
    // `centered'
    for (vector<string>::const_iterator curr = words.begin(); curr != words.end(); curr++) {

    	string::size_type curr_size = curr->size();
    	string::size_type n_blanks_left = (maxlen - curr_size) / 2;
    	string::size_type n_blanks_right = maxlen - (n_blanks_left + curr_size);

    	centered.push_back("* " +
    			   string(n_blanks_left, ' ') +
    			   *curr +
    			   string(n_blanks_right, ' ') +
    			   " *");
    }

    // add bottom of picture frame
    centered.push_back(string(maxlen + 4, '*'));
    
    return centered;
}
