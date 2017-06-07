/* Page 73
 *
 * Now change your squares program to use double values instead of ints. Use
 * manipulators to manage the output so that the values line up in columns.
 */

#define START_VAL -1.0    // starting value of sequence
#define END_VAL    4.0    // maximum value in sequence can be no larger
#define BY_VAL     0.125  // distance between values in sequence
#define COL_PAD    "    " // blank space between columns

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "calc_nchars.h"
#include "calc_seq.h"

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::streamsize;
using std::setw;




int main() {

    vector<double> orig_vals, square_vals;
    vector<string> orig_chars, square_chars;
    vector<int> orig_after, square_after;
    int max_orig_before, max_orig_after, max_square_before, max_square_after;
    int orig_width, square_width;
    int n_rows;

    // obtain the sequence of numbers that are to be squared
    orig_vals = calc_seq(START_VAL, END_VAL, BY_VAL);
    n_rows = orig_vals.size();

    // calculate sequence of squared numbers
    for (int i = 0; i < n_rows; i++) {
	square_vals.push_back(orig_vals[i] * orig_vals[i]);
    }

    /* convert numerical vectors to their character representation and count how
     * many digits are before and after the radix character for each number, and
     * the overall maxes for each column
     */
    calc_width_prec(orig_vals,
		    square_vals,
		    orig_chars,
		    square_chars,
		    orig_after,
		    square_after,
		    max_orig_before,
		    max_orig_after,
		    max_square_before,
		    max_square_after);

    /* calculate the max width of each column.  If there are any digits after
     * the radix character then add 1 to account for that character, otherwise
     * don't add 1 since it will be dropped later.
     */
    orig_width = (max_orig_after > 0) ? max_orig_before + max_orig_after + 1 : max_orig_before;
    square_width = (max_square_after > 0) ?
	max_square_before + max_square_after + 1 :
	max_square_before;

    // each iteration prints out one row of the table
    for (int i = 0; i < n_rows; i++) {

	/* pad current character representation with trailing zeroes, or strip
	 * decimal point if all values are integers
	 */
	string curr_orig = (max_orig_after > 0) ?
	    orig_chars[i] + string(max_orig_after - orig_after[i], '0') :
	    orig_chars[i].substr(0, orig_chars[i].size() - 1);
	string curr_square = (max_square_after > 0) ?
	    square_chars[i] + string(max_square_after - square_after[i], '0') :
	    square_chars[i].substr(0, square_chars[i].size() - 1);

	// write current line of output to stdout
	cout << setw(orig_width)   << curr_orig
	     << COL_PAD
	     << setw(square_width) << curr_square
	     << "\n";
    }

    return 0;
}
