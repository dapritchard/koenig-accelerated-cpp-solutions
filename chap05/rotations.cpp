#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "rotations.h"
#include "split.h"

#define TABLE_PADDING "    "

using std::vector;
using std::string;
using std::istream;
using std::getline;
using std::ostream;




/* reads an istream line-by-line, tokenizes the line into words, and then
 * appends the set of all `permute_pair' rotations for the line to a vector of
 * `permute_pair's.  Return object is the vector of all of the `permute_pair's
 * for all of the lines.
 */
vector<permute_pair> stream_to_rotations(istream& input) {

    string line;
    vector<permute_pair> pairs;

    /* each iteration reads one line of input, tokenizes the words in the line,
     * and then appends the set of all `permute_pair' rotations for the line to
     * `pairs'
     */
    while (getline(input, line)) {

	// split line into words
	vector<string> curr_words = split(line);

	// append each of the permutations from the line to `pairs'
	rotations(curr_words, pairs);
    }

    return pairs;
}




/* appends a set of entries to `pairs', where the set is the permutations given
 * by `words'
 */
void rotations(const vector<string>& words, vector<permute_pair>& pairs) {

    vector<string>::const_iterator begin;
    vector<string>::const_iterator end;
    vector<string>::const_iterator split;

    begin = words.begin();
    end = words.end();

    /* each iteration calculates the phrase and corresponding index for one of
     * the rotations and appends it to `pairs'
     */
    for (split = begin; split != end; split++) {
	permute_pair curr;
	curr.phrase = concatenate(words, begin, split);
	curr.index = concatenate(words, split, end);
	pairs.push_back(curr);
    }
}




/* concatenates the strings in `words', separated by blanks and in the order
 * they appear in the vector, starting at the string pointed to by `begin', and
 * ending one before the string pointed to by end
 */
string concatenate(const vector<string>& words,
		   vector<string>::const_iterator begin,
		   vector<string>::const_iterator end) {

    /* return empty string if [`begin', `end') is empty.  Note that this
     * conditional evaluates to true if `words' is empty
     */
    if (begin >= end) {
	return "";
    }

    // initialize a string with the first word in the vector
    string accumulate = *begin;
    begin++;

    // each iteration appends one word in the vector to string
    for ( ; begin != end; begin++) {
    	accumulate += " " + *begin;
    }

    return accumulate;
}




// evaluates to true if a < b lexographically (case insensitive)
bool compare_permute_pairs(const permute_pair& a, const permute_pair& b) {
    return string_to_lower(a.index) < string_to_lower(b.index);
}




/* returns a string identical to `word' but with uppercase chars (if any)
 * converted to lowercase chars
 */
string string_to_lower(const string& word) {
    
    string lower;

    for (string::size_type i = 0; i < word.size(); i++) {
	lower.push_back(tolower(word[i]));
    }

    return lower;
}




/* returns the length of the longest phrase element of a `permute_pair' in the
 * vector `pairs'
 */
string::size_type max_phrase_len(vector<permute_pair> pairs) {
    
    string::size_type max_phrase_len = 0;
    
    for (unsigned int i = 0; i < pairs.size(); i++) {
	if (pairs[i].phrase.size() > max_phrase_len) {
	    max_phrase_len = pairs[i].phrase.size();
	}
    }

    return max_phrase_len;
}




/* writes a permuted index to `output', where the phrase column is right-aligned
 * and the index-column is left-aligned, and the two columns are separated by
 * TABLE_PADDING
 */
void write_permuted_idx(const vector<permute_pair>& pairs, ostream& output) {

    string::size_type maxlen = max_phrase_len(pairs);

    for (vector<permute_pair>::const_iterator curr = pairs.begin();
	 curr < pairs.end();
	 curr++) {
	
	output << string(maxlen - curr->phrase.size(), ' ')
	       << curr->phrase
	       << TABLE_PADDING
	       << curr->index
	       << "\n";
    }
}
