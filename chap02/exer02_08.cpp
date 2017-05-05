/* Page 34
 *
 * Write a program to generate the product of the numbers in the range [1, 10).
 */

#include <iostream>


int main() {

    int prod_val = 1;

    for (int k = 2; k < 10; k++) {
	prod_val *= k;
    }

    std::cout << "The product of the integers in the range [1, 10) is:  "
	      << prod_val
	      << "\n";

    return 0;
}
