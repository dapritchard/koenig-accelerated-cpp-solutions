#include <algorithm>
#include <string>
#include <vector>
#include "pics.h"

using std::string;
using std::vector;
using std::max;




string::size_type width(const vector<string>& v) {
    
    string::size_type maxlen = 0;

    // each iteration compares the length of the current string with maxlen and
    // updates maxlen if it is bigger
    vector<string>::const_iterator curr, end;
    end = v.end();
    for (curr = v.begin(); curr != end; curr++) {
	maxlen = max(maxlen, curr->size());
    }
    return maxlen;
}




vector<string> frame(const vector<string>& v) {
    
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // write the top border
    ret.push_back(border);

    // write each interior row, bordered by an asterisk and a space
    vector<string>::const_iterator curr, end;
    end = v.end();
    for (curr = v.begin(); curr != end; curr++) {
	ret.push_back("* " + *curr + string(maxlen - curr->size(), ' ') + " *");
    }

    // write the bottom border
    ret.push_back(border);
    
    return ret;
}



	
// vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
    
//     // copy the `top' picture
//     vector<string> ret = top;

//     // copy entire `bottom' picture
//     for (vector<string>::const_iterator it = bottom.begin();
// 	 it != bottom.end(); ++it)
// 	ret.push_back(*it);

//     return ret;
// }




vector<string> hcat(const vector<string>& left, const vector<string>& right) {
    
    vector<string> ret;

    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;

    // iterators to look at elements from `left' and `right' respectively
    vector<string>::const_iterator lcurr, lend, rcurr, rend;
    lcurr = left.begin();
    lend = left.end();
    rcurr = right.begin();
    rend = right.end();
    
    // continue until we've seen all rows from both pictures
    while (lcurr != lend || rcurr != rend) {
	
	// construct new `string' to hold characters from both pictures
	string s;

	// copy a row from the left-hand side, if there is one
	if (lcurr != lend) {
	    copy(lcurr->begin(), lcurr->end(), back_inserter(s));
	    lcurr++;
	}

	// pad to full width
	s += string(width1 - s.size(), ' ');

	// copy a row from the right-hand side, if there is one
	if (rcurr != rend) {
	    copy(rcurr->begin(), rcurr->end(), back_inserter(s));
	    rcurr++;
	}

	// add `s' to the picture we're creating
	ret.push_back(s);
    }

    return ret;
}
