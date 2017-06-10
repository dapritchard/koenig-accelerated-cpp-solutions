/* Page 73
 *
 * Write a program to calculate the average of the numbers stored in a
 * vector<double>.
 */

#include <iostream>
#include <vector>
#include "vec_dbl_ave.h"

using std::cout;
using std::vector;

static const double hardcoded_vals[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
vector<double> one_to_ten(hardcoded_vals, hardcoded_vals + 10);



int main() {

    cout << "The average of 1, 2, ..., 10 is:  " << vec_dbl_ave(one_to_ten) << "\n";

    return 0;
}
