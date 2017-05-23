/* Page 73
 *
 * Write a program to calculate the squares of int values up to 100. The program
 * should write two columns: The first lists the value; the second contains the
 * square of that value. Use setw (described above) to manage the output so that
 * the values line up in columns.
 */

#define MAXINT           100    // largest integer to print
#define MAXINT_NCHARS      3    // num chars in character repr of MAXINT
#define MAXINT_SQ_NCHARS   5    // num chars in character repr of MAXINT^2

#define PADDING "    "

#include <iostream>
#include <iomanip>

using std::cout;
using std::setw;



int main() {

    for (int k = 1; k <= MAXINT; k++) {
	
	cout << setw(MAXINT_NCHARS) << k
	     << PADDING
	     << setw(MAXINT_SQ_NCHARS) << k * k << "\n";
    }

    return 0;
}
