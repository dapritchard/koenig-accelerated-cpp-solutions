// Page 138
//
// Change the cross-reference program to find all the URLs in a file, and write all the
// lines on which each distinct URL occurs.

#include <map>
#include <iostream>
#include <string>
#include <vector>
#include "split.h"
#include "urls.h"

#define COLWIDTH     60
#define SCREENWIDTH 100

using std::cin;            using std::cout;
using std::endl;           using std::getline;
using std::istream;        using std::string;
using std::vector;         using std::map;




// find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in,
			       vector<string> find_words(const string&) = split) {
    
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    // read the next line
    while (getline(in, line)) {
	
	++line_number;

	// break the input line into words
	vector<string> words = find_words(line);

	// remember that each word occurs on the current line
	for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {

	    // case: we have not yet seen this line number for this word.  Note
	    // that the call to `ret[*it].back()' is always valid because if the
	    // key exists then an element was written to the vector at the time
	    // of initialization.
	    if (ret.find(*it) == ret.end() || ret[*it].back() != line_number) {
		ret[*it].push_back(line_number);
	    }
	}
    }
    return ret;
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




int main() {

    const string indent(COLWIDTH, ' ');

    // read input and construct an associative container mapping the lines on
    // which they appear to words
    map<string, vector<int> > ret = xref(cin, find_urls);

    // write the results
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {

	int nchars;
	
	// construct first section of line
	string line_statement = (it->second.size() == 1) ?
	    it->first + " occurs on line:" :
	    it->first + " occurs on lines:";

	// if necessary, pad line to COLWIDTH chars
	if ((nchars = line_statement.size()) < COLWIDTH) {
	    line_statement += string(COLWIDTH - nchars, ' ');
	    nchars = COLWIDTH;
	}
	// otherwise add two chars of separation
	else {
	    line_statement += "  ";
	    nchars += 2;
	}

	// print the word declaration portion of the line
	cout << line_statement;

	// each iteration prints 
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
		cout << "\n" + indent << *line_it << ", ";
		nchars = COLWIDTH + curr_num_sz + 2;
	    }
	    // case: exactly enough room on this line, if we omit a blank after
	    // the comma
	    else if (nchars - 1 == SCREENWIDTH) {
		cout << *line_it << ",";
	    }
	    // case: enough room on this line for a trailing ", " after the
	    // number
	    else {
		cout << *line_it << ", ";
	    }
	}

	// print the last number
	(nchars + calc_nchars(*line_it) <= SCREENWIDTH) ?
	    cout << *line_it << "\n" :
	    cout << "\n" + indent << *line_it << "\n";
    }

    return 0;
}
