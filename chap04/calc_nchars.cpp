#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include "calc_nchars.h"

using std::vector;
using std::string;


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




/* convert the vectors of doubles `orig_vals' and `square_vals' to character
 * representations stored in `orig_chars' and `square_chars', respectively.
 * Furthermore, records the number of characters after the radix character for
 * each value and stores these values in `orig_after' and `square_after'.  Also
 * records the max number of characters before and after the radix character for
 * each column, which are stored in `max_orig_before' and `max_orig_after'
 * (column 1) and `max_square_before' and `max_square_after' (column 2).
 */

void calc_width_prec(const vector<double> orig_vals,
		     const vector<double> square_vals,
		     vector<string>& orig_chars,
		     vector<string>& square_chars,
		     vector<int>& orig_after,
		     vector<int>& square_after,
		     int& max_orig_before,
		     int& max_orig_after,
		     int& max_square_before,
		     int& max_square_after) {

    /* initialize variables tracking the most digits needed before and after the
     * radix character to represent the values
     */
    max_orig_before = max_orig_after = max_square_before = max_square_after = 0;

    /* each iteration converts the i-th value and its square into their
     * character representations, counts how many digits are before and after
     * the radix character, and possible updates the variables storing the max
     * digits before and after the radix character for each column.
     */
    for (unsigned int i = 0; i < orig_vals.size(); i++) {
	
	double curr_orig, curr_square;
	char curr_char_orig[DEC_BUF_SIZE], curr_char_square[DEC_BUF_SIZE];
	int curr_orig_before, curr_orig_after;
	int curr_square_before, curr_square_after;

	// calculate square of current value
	curr_orig = orig_vals[i];
	curr_square = curr_orig * curr_orig;

	/* obtain character representations of current original and squared
	 * values and store in buffers
	 */
	snprintf(curr_char_orig, DEC_BUF_SIZE, "%.*f", DEC_BUF_SIZE, curr_orig);
	snprintf(curr_char_square, DEC_BUF_SIZE, "%.*f", DEC_BUF_SIZE, curr_square);

	/* calculate number of digits needed before and after the radix
	 * character to represent the values
	 */
	ndig_before_after(curr_char_orig, &curr_orig_before, &curr_orig_after);
	ndig_before_after(curr_char_square, &curr_square_before, &curr_square_after);

	// terminate C strings with null byte
	curr_char_orig[curr_orig_before + curr_orig_after + 1] = '\0';
	curr_char_square[curr_square_before + curr_square_after + 1] = '\0';

	// store character representations to vectors
	orig_chars.push_back(curr_char_orig);
	square_chars.push_back(curr_char_square);

	// store number of digits after the radix character to vectors
	orig_after.push_back(curr_orig_after);
	square_after.push_back(curr_square_after);
	
	/* update variables tracking the most digits needed before and after the
	 * radix character to represent the values
	 */
	if (curr_orig_before > max_orig_before)     max_orig_before   = curr_orig_before;
	if (curr_orig_after > max_orig_after)       max_orig_after    = curr_orig_after;
	if (curr_square_before > max_square_before) max_square_before = curr_square_before;
	if (curr_square_after > max_square_after)   max_square_after  = curr_square_after;
    }
}




/* calculate the number of digits before and after the radix character for the
 * character representation of a number pointed to by `char_repr'.  The number
 * of digits before and after are stored in memory pointed to by `n_before' and
 * `n_after'.
 */
void ndig_before_after(const char *char_repr, int *n_before, int *n_after) {

    int ldig_idx, radix_idx;

    /* position `ldig_idx' to index the last nonzero character of char_repr
     * (which could be the radix character).  Note that `strlen(char_repr) - 1'
     * is the index of the last character in the string and is guaranteed to be
     * nonnnegative.
     */
    for (ldig_idx = strlen(char_repr) - 1; char_repr[ldig_idx] == '0'; ldig_idx--) {
	// noop
    }
    // position `radix_idx' to index the radix character of char_repr
    for (radix_idx = ldig_idx; char_repr[radix_idx] != '.'; radix_idx--) {
	// noop
    }

    /* the number of characters before the radix character is equal to the index
     * of the radix character, due to 0-based indexing
     */
    *n_before = radix_idx;
    /* the number of characters after the radix character is equal to the index
     * of the last digit minus the index of the radix
     */
    *n_after =  ldig_idx - radix_idx;
}

