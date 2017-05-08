/* Page 49
 *
 * Write a program to report the length of the longest and shortest string in
 * its input.
 */

#include <iostream>
#include <string>


int main() {

    std::string word;
    std::string::size_type shortest, longest, word_size;

    std::cout << "Please enter a list of words followed by an EOF character:  ";

    /* read the first word from stdin and initialize shortest word and longest
     * word variables as the length of this word.
     */
    if (std::cin >> word) {
	shortest = longest = word.size();
    }
    else {
	std::cout << "error: no words entered as input\n";
    }

    /* each iteration reads a word from stdin and compares its size with the
       size of the previous shortest (longest) word, and updates the size of the
       current shortest (longest) word if it is shorter (longer).
     */
    while (std::cin >> word) {

	word_size = word.size();

	/* case: current word is shorter than previous shortest, so update
	 * variable storing the size of the shortest word seen so far
	 */
	if (word_size < shortest) {
	    shortest = word_size;
	}
	/* case: current word is longer than previous longest, so update
	 * variable storing the size of the longest word seen so far
	 */
	else if (word_size > longest) {
	    longest = word_size;
	}
    }

    std::cout << "The length of the shortest string was:  "  << shortest << "\n"
	      << "The length of the longest string was:   "  << longest << "\n";

    return 0;
}
