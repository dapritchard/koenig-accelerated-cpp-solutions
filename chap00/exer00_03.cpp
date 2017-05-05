/* Page 7
 *
 * The string literal "\t" represents a tab character; different C++
 * implementations display tabs in different ways.  Experiment with your
 * implementation to learn how it treats tabs.
 */

#include <iostream>

int main() {

    std::cout << "These colons are separated by a tab:\t:" << std::endl;
    std::cout << "\t<-- Leading with a tab" << std::endl;

    return 0;
}
