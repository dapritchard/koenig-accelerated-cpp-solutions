/* Page 49
 *
 * Write a program to compute and print the quartiles on a set of integers.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::sort;


int main() {
    
    // ask for and read the data
    cout << "Please enter a set of integers followed by an EOF character:  ";

    vector<double> data_vals;
    double x;
    // invariant: `data_vals' contains all the data_vals read so far.  Warning:
    // does not check for invalid input!
    while (cin >> x) {
	data_vals.push_back(x);
    }

    // check that the student entered some values
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = data_vals.size();
    if (size == 0) {
	cout << "\nYou must enter your grades.  "
	     << "Please try again.\n";
	return 1;
    }

    // sort the data
    sort(data_vals.begin(), data_vals.end());

    // calculate quantile estimates.  Subtract 1 to adjust for zero-based
    // indexing.
    double first_quart, second_quart, third_quart;
    first_quart  = data_vals[ceil(0.25 * size) - 1];
    second_quart = data_vals[ceil(0.50 * size) - 1];
    third_quart  = data_vals[ceil(0.75 * size) - 1];

    // write quartile estimates to stdout
    cout << "The first quartile is:   " << first_quart << "\n"
	 << "The second quartile is:  " << second_quart << "\n"
	 << "The third quartile is:   " << third_quart << "\n";

    return 0;
}
