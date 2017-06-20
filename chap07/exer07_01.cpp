// Extend the program from section 7.2 page 124 to produce its output sorted by
// occurrence count.  That is, the output should group all the words that occur
// once, followed by those that occur twice, and so on.

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::map;
using std::vector;
using std::string;
using std::sort;


int main()
{
    string s;
    map<string, int> counters;     // store each word and an associated counter
    map<int, vector<string> > wc;  // store words keyed by number of times seen

    // read the input, keeping track of each word and how often we see it
    while (cin >> s) {
	++counters[s];
    }

    // step through the different words and store in a map with the key given by
    // the number of times each word was seen
    for (map<string, int>::const_iterator curr = counters.begin();
	 curr != counters.end();
	 curr++) {
	
	wc[curr->second].push_back(curr->first);
    }
    
    // write the words and associated counts
    for (map<int, vector<string> >::iterator curr = wc.begin(); 
    	 curr != wc.end();
    	 curr++) {

	// sort words under current word count lexicographically
    	sort(curr->second.begin(), curr->second.end());

	// header for current word count class of words
	cout << "seen " << curr->first << " time(s)\n"
	     << "------------------\n";

	// print each word in current word count class of words
	for (vector<string>::const_iterator wcurr = curr->second.begin();
	     wcurr != curr->second.end();
	     wcurr++) {
	    
	    cout << *wcurr << "\n";
	}
	cout << "\n\n";
    }

    return 0;
}
