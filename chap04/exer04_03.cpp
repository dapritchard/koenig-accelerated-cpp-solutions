/* Page 73
 *
 * What happens if we rewrite the previous program to allow values up to but not
 * including 1000 but neglect to change the arguments to setw?  Rewrite the
 * program to be more robust in the face of changes that allow i to grow without
 * adjusting the setw arguments.
 */

#define MAXINT  999
#define PADDING "    "

#include <iostream>
#include <iomanip>
#include "calc_nchars.h"

using std::cout;
using std::setw;


int main() {

    int c1_size, c2_size;

    // calculate the number of chars in the largest value in the column
    c1_size = calc_nchars(MAXINT);
    c2_size = calc_nchars(MAXINT * MAXINT);    
    
    for (int k = 1; k <= MAXINT; k++) {
	
	cout << setw(c1_size) << k
	     << PADDING
	     << setw(c2_size) << k * k << "\n";
    }

    return 0;
}
