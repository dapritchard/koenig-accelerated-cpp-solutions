#include <cstdlib>
#include <ctime>
#include <stdexcept>

using std::domain_error;




// return a random integer in the range [0, n), where `n' is required to be <=
// `RAND_MAX'.

int nrand(int n) {
    
    if (n <= 0 || n > RAND_MAX) {
	throw domain_error("Argument to nrand is out of range");
    }

    const int bucket_size = RAND_MAX / n;
    int r;
    timespec seed;

    do {
	clock_gettime(CLOCK_MONOTONIC, &seed);
	srand(seed.tv_nsec);
	r = rand() / bucket_size;
    } while (r >= n);

    return r;
}




// used as a pretend version of RAND_MAX so that we can sample data on a small
// range of numbers and study their properties.  For example, we can run
// `extend_nrand(65)' for 10,000,000 trials in a few seconds and see whether the
// numbers in { 0, 1, ..., 64 } appear to be random.

#define FAUX_RAND_MAX 7


// return a random integer in the range [0, n), where `n' is allowed to be any
// number <= `INT_MAX'.

unsigned long extend_nrand(unsigned long n) {

    if (n <= 0) {
	throw domain_error("Argument to faux_extend_nrand is out of range");
    }
    else if (n <= FAUX_RAND_MAX) {
	return nrand(n);
    }

    // if we've made it here then n >  FAUX_RAND_MAX

    // calculate ceil(n / FAUX_RAND_MAX)
    unsigned long curr_lev = (n % FAUX_RAND_MAX) ?
	n / FAUX_RAND_MAX + 1 :
	n / FAUX_RAND_MAX;

    // return a uniform number in [0, curr_lev * FAUX_RAND_MAX).  Note that the
    // upper bound may be greater than n.  The way that this works is the
    // following.  The expression
    //
    //     curr_lev * faux_nrand(FAUX_RAND_MAX)
    //
    // gives us `k * curr_lev', where k is in { 0, 1, ..., FAUX_RAND_MAX - 1 }.
    // Then, the recursive call to `faux_extend_nrand(curr_lev)' gives us a
    // uniform number, say m, in { 0, 1, ..., curr_lev - 1 }.
    //
    // So the probability of getting any number in the stated range is to draw
    // exactly the right k, and then draw exactly the right m, which is given by
    //
    //                                   1             1
    //     P(draw k) x P(draw m) = ------------- x --------
    //                             FAUX_RAND_MAX   curr_lev
    
    unsigned long total = curr_lev * nrand(FAUX_RAND_MAX) + extend_nrand(curr_lev);

    // the above scheme may not yield a valid number.  If so then start over
    // from the top.
    return (total < n) ? total : extend_nrand(n);
}
