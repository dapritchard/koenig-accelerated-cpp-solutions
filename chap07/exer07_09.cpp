// The implementation of nrand in section 7.4.4 page 135 will not work for
// arguments greater than RAND_MAX.  Usually, this restriction is no problem,
// because RAND_MAX is often the largest possible integer anyway.  Nevertheless,
// there are implementations under which RAND_MAX is much smaller than the
// largest possible integer.  For example, it is not uncommon for RAND_MAX to be
// 32767 (2^15 - 1) and the largest possible integer to be 2147483647 (2^31 -
// 1).  Reimplement nrand so that it works well for all values of n.

#include <iostream>
#include "nrand.h"

using std::cout;


int main() {

    // arbitrarily number of samples
    int nsamp = 1000000;

    // arbitrary choice of 65 as a small number that we can check to assay
    // whether it has a uniform distribution
    for (int i = 0; i < nsamp; i++) {
    	cout << extend_nrand(65) << "\n";
    }

    return 0;
}
