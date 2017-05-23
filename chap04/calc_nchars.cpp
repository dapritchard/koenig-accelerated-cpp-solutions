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
