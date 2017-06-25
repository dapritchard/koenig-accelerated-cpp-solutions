// Page 154
//
// Reimplement the xref function from Chapter 7 to use output iterators rather
// than writing their output directly to a vector<string>. Test this new version
// by writing a program that attaches the output iterator directly to the
// standard output.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include "split.h"

// define the width in chars of the start of the line numbers column, and the
// width of the screen, respectively
#define COLWIDTH    40
#define SCREENWIDTH 60

using std::cin;            using std::cout;
using std::endl;           using std::getline;
using std::istream;        using std::string;
using std::vector;         using std::map;
using std::to_string;      using std::ostream_iterator;

// function declarations
int calc_nchars(int val);
template <class Out>
Out write_xref(Out& dest, map<string, vector<int> > tab);
template <class Out>
Out xref(istream& in, Out& dest, vector<string> find_words(const string&) = split);




// begin main ------------------------------------------------------------------

int main() {

    ostream_iterator<string> out(cout, "\n");
    xref(cin, out);

    return 0;
}




// begin supporting functions --------------------------------------------------

// find all the lines that refer to each word in the input
template <class Out>
Out xref(istream& in, Out& dest, vector<string> find_words(const string&)) {
    
    string line;
    int line_number = 0;
    map<string, vector<int> > tab;

    // read the next line
    while (getline(in, line)) {
	
	++line_number;

	// break the input line into words
	vector<string> words = find_words(line);

	// remember that each word occurs on the current line
	for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {

	    // case: we have not yet seen this line number for this word.  Note
	    // that the call to `tab[*it].back()' is always valid because if the
	    // key exists then an element was written to the vector at the time
	    // of initialization.
	    if (tab.find(*it) == tab.end() || tab[*it].back() != line_number) {
		tab[*it].push_back(line_number);
	    }
	}
    }

    return write_xref(dest, tab);
}




// formats each string and vector<int> pair into a cross-reference table with
// the strings as the keywords in alphabetical order.  Each line of the table is
// written to `dest'.

template <class Out>
Out write_xref(Out& dest, map<string, vector<int> > tab) {

    // write the results
    for (map<string, vector<int> >::const_iterator it = tab.begin(); it != tab.end(); ++it) {

	int nchars;
	const string indent(COLWIDTH, ' ');
	
	// construct first section of line
	string line = (it->second.size() == 1) ?
	    it->first + " occurs on line:" :
	    it->first + " occurs on lines:";

	// if necessary, pad line to COLWIDTH chars
	if ((nchars = line.size()) < COLWIDTH) {
	    line += string(COLWIDTH - nchars, ' ');
	    nchars = COLWIDTH;
	}
	// case: word is over the column width, simply add two spaces padding
	else {
	    line += "  ";
	    nchars += 2;
	}

	// each iteration adds one number followed by a ", " or a ",".  If
	// SCREENWIDTH is reached, then `line' is written to `dest++', and a new
	// line is started by overwritting `line' with the appropriate padding.
	vector<int>::const_iterator line_it;
	for (line_it = it->second.begin(); line_it + 1 < it->second.end(); line_it++) {

	    // if we include the current number on this line then the number of
	    // chars will be the current amount plus the length in chars of the
	    // new number plus two chars for the trailing ", "
	    int curr_num_sz = calc_nchars(*line_it);
	    nchars += curr_num_sz + 2;

	    // case: not enough room on this line, start on the next line.  The
	    // -1 in the conditional is because we've included a char for the
	    // trailing blank, which we can omit if needed
	    if (nchars - 1 > SCREENWIDTH) {
		*dest++ = line;
		line = indent + to_string(*line_it) + ", ";
		nchars = COLWIDTH + curr_num_sz + 2;
	    }
	    // case: exactly enough room on this line, if we omit a blank after
	    // the comma
	    else if (nchars - 1 == SCREENWIDTH) {
		line += to_string(*line_it) + ",";
	    }
	    // case: enough room on this line for a trailing ", " after the
	    // number
	    else {
		line += to_string(*line_it) + ", ";
	    }
	}

	// print the last number
	if (nchars + calc_nchars(*line_it) <= SCREENWIDTH) {
	    line += to_string(*line_it);
	}
	else {
	    *dest++ = line;
	    line = indent + to_string(*line_it) + "\n";
	}
	*dest++ = line;
	
    }

    return dest;
}




// calculates the number of chars used in the character representation of val
int calc_nchars(int val) {

    // special case not properly handled by the following algorithm
    if (val == 0) {
	return 1;
    }

    /* `nchars' is used as a counter to track the number of digits in `val'.  If
     * `val' is negative then make `val' positive and add 1 to the counter to
     * account for the negative sign.
     */
    int nchars = 0;
    if (val < 0) {
	val *= -1;
	nchars = 1;
    }

    // divide by 10 accounts for leading digit in current value of `val'
    for (; val > 0; val /= 10) {
	nchars++;
    }
    
    return nchars;
}
