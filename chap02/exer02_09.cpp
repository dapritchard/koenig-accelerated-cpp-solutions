/* Page 34
 *
 * Write a program that asks the user to enter two numbers and tells the user
 * which nuber is larger than the other.
 */

#include <iostream>


int main() {

    int val1;
    int val2;

    std::cout << "Please enter an integer value:  ";
    std::cin >> val1;

    std::cout << "Please enter another integer value:  ";
    std::cin >> val2;

    // write the first number to stdout
    std::cout << val1;

    // write a message declaring which is bigger to stdout
    if (val1 > val2) {
	std::cout << " is greater than ";
    }
    else if (val1 == val2) {
	std::cout << " is equal to ";
    }
    else {
	std::cout << " is less than ";
    }

    // write the second number to stdout
    std::cout << val2;
    std::cout << "\n";

    return 0;
}
