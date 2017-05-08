/* Page 49
 *
 * Write a program to count how many times each distinct word appears in its input.
 */

/* Note that this is a highly inefficient way to answer this question.  A more
 * efficient implementation might use trees or hashing to store / look for words
 * in a dictionary.
 */

#include <iostream>
#include <vector>
#include <string>


int main() {

    std::vector<std::string> dict_vec;             // vector of distinct words
    std::vector<unsigned int> wcount_vec;     // number of times we've seen word
    std::vector<std::string>::size_type word_idx;  // index of word in dict_vec
    std::string curr_word;
    
    std::cout << "Please enter a list of words followed by an EOF character:  ";

    /* each iteration reads in a word from stdin and adds 1 to the word count of
     * that word.  This process may include adding the word to the dictionary if
     * we haven't yet seen it.
     */
    while (std::cin >> curr_word) {

	/* search for current word in the dictionary.  Each iteration steps
	 * through the dictionary and checks the current word against the
	 * word_idx-th word in the dictionary and breaks the loop if it is a
	 * match.  When the loop ends, word_idx either has the value of the
	 * index corresponding to the word in dict_vec, or has the value of 1
	 * past the last value in dist_vec.
	 */
	for (word_idx = 0; word_idx < dict_vec.size(); word_idx++) {

	    if (curr_word == dict_vec[word_idx]) {
		wcount_vec[word_idx]++;
		break;
	    }
	}

	
	/* case: we haven't seen the word yet.  Add to word list and set the
	 * number of times we've seen this word to 1.
	 */
	if (word_idx == dict_vec.size()) {
	    dict_vec.push_back(curr_word);
	    wcount_vec.push_back(1);
	}
    }

    // print word counts
    std::cout << "Word counts:\n"
	      << "------------\n";
    for (word_idx = 0; word_idx < dict_vec.size(); word_idx++) {
	std::cout << dict_vec[word_idx] << "\t\t"
		  << wcount_vec[word_idx] << "\n";
    }

    return 0;
}
