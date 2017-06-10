/* Page 73
 *
 * Write a function that reads words from an input stream and stores them in a
 * vector.  Use that function both to write programs that count the number of
 * words in the input, and to count how many times each word occurred.
 */

/* note that this exercise is very similar to exercise 3-3 and several sections
 * of code are copied / adapted from that exercise
 */

#include <iostream>
#include <vector>
#include <string>
#include "count_unique_in_stream.h"

using std::cin;
using std::cout;
using std::vector;
using std::string;


int main() {

    vector<string> word_vec, unique_vec;
    vector<int> wcount_vec;

    // read in stream and return vector of words
    word_vec = stream_to_words(cin, cout);
    // store a vector with a list and count of unique words
    n_unique(word_vec, unique_vec, wcount_vec);

    // print word counts
    std::cout << "Word counts:\n"
	      << "------------\n";
    for (unsigned int i = 0; i < unique_vec.size(); i++) {
	std::cout << unique_vec[i] << "\t\t"
		  << wcount_vec[i] << "\n";
    }

    return 0;
}
