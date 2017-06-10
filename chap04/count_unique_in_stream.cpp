#include <iostream>
#include <vector>
#include <string>

using std::istream;
using std::ostream;
using std::vector;
using std::string;




/* tokenize words from `stream' and store in a vector of strings in the same
 * order in which words were read, which is then returned by the function
 */

vector<string> stream_to_words(istream& input, ostream& output) {

    vector<string> word_vec;
    string curr_word;

    // case: input not already in fail state
    if (input) {

	output << "Please enter a list of words followed by an EOF character:  ";
	while (input >> curr_word) {
	    word_vec.push_back(curr_word);
	}

	// reset stream state for possible future use
	input.clear();
    }	

    return word_vec;
}




/* counts the number of times each word is present in `word_vec'.  If a word in
 * `word_vec' is present in `unique_vec', then the number of times it is seen is
 * added to the entry with the same index in `wcount_vec', otherwise the word is
 * appended to `unique_vec'.
 *
 * Note that this implementation is a highly inefficient way to perform this
 * task.  A more efficient implementation might use trees or hashing to store /
 * look for words in a dictionary.
 */

void n_unique(const vector<string> word_vec,
	      vector<string>& unique_vec,
	      vector<int>& wcount_vec) {

    // ensure that unique_vec and wcount_vec are empty
    unique_vec.clear();
    wcount_vec.clear();

    /* each iteration either (i) adds the i-th word in word_vec to the end of
     * unique_vec if the word has not yet been seen, or (ii) adds 1 to the count
     * stored in wcount_vec of the number of times we have seen the word.
     */
    for (unsigned int i = 0; i < word_vec.size(); i++) {
	
	string curr_word = word_vec[i];
	
	/* search for current word in the unique word vector.  Each iteration
	 * steps through the unique word vector and checks the current word
	 * against the j-th word in the unique word vector and breaks the loop
	 * if it is a match.  When the loop ends, j either has the value of the
	 * index corresponding to the word in unique_vec, or has the value of 1
	 * past the index of the last word in unique_vec.
	 */
	unsigned int j;
	for (j = 0; j < unique_vec.size(); j++) {
	    if (curr_word == unique_vec[j]) {
		wcount_vec[j]++;
		break;
	    }
	}

	/* case: we haven't seen the word yet.  Add to word list and set the
	 * number of times we've seen this word to 1.
	 */
	if (j == unique_vec.size()) {
	    unique_vec.push_back(curr_word);
	    wcount_vec.push_back(1);
	}
    }
}
