/* Page 34
 *
 * Write a set of "*" characters so that they form a square, a rectangle, and a
 * triangle.
 */


#include <iostream>
#include <string>


int main() {

    std::string star_row;
    std::string blank_row;
    std::string tri_row;

    // square section of code ------------------------------
    
    /* ask for the number of blank characters to use for the square size.  Note
     * that for the program to function correctly an integer of >= 2 must be
     * provided.  Warning: does not check that a valid input is provided!
    */
    std::cout << "Please enter an integer >= 2 for the square size:  ";
    int square_size;
    std::cin >> square_size;

    // create the top / bottom row and interior row.  Precondition: assumes that
    // square size >= 2.
    star_row = std::string(square_size, '*');
    blank_row = "*" + std::string(square_size - 2, ' ') + "*";

    /* each iteration writes a line of the square.  Invariant: we have written r
     * rows of the square so far.
     */
    for (int r = 0; r < square_size; r++) {
	if (r == 0 || r == square_size - 1) {
	    std::cout << star_row << "\n";
	}
	else {
	    std::cout << blank_row << "\n";
	}
    }


    // rectangle section of code ---------------------------

    /* ask for the number of blank characters to use for the rectangle height
     * and width.  Note that for the program to function correctly an integer of
     * >= 2 must be provided for each dimension.  Warning: does not check that a
     * valid input is provided!
     */
    int rect_height;
    int rect_width;
    std::cout << "Please enter an integer >= 2 for the rectangle height:  ";
    std::cin >> rect_height;
    std::cout << "Please enter an integer >= 2 for the rectangle width:  ";
    std::cin >> rect_width;

    // create the top / bottom row and interior row.  Precondition: assumes that
    // square size >= 2.
    star_row = std::string(rect_width, '*');
    blank_row = "*" + std::string(rect_width - 2, ' ') + "*";

    /* each iteration writes a line of the square.  Invariant: we have written r
     * rows of the square so far.
     */
    for (int r = 0; r < rect_height; r++) {
	if (r == 0 || r == rect_height - 1) {
	    std::cout << star_row << "\n";
	}
	else {
	    std::cout << blank_row << "\n";
	}
    }
    
    
    // triangle section of code ----------------------------

    /* ask for the number of blank characters to use for the triangle height.
     * Note that for the program to function correctly an integer of >= 2 must
     * be provided.  Warning: does not check that a valid input is provided!
     */
    std::cout << "Please enter an integer >= 2 for the triangle height:  ";
    int tri_height;
    std::cin >> tri_height;

    /* each iteration writes a line of the triangle, stopping at the
     * second-to-last line.  Invariant: we have written r rows of triangle so
     * far.
     */
    std::cout << "*\n";
    for (int r = 1; r < tri_height - 1; r++) {
	std::cout << "*" + std::string(1 + 2 * (r - 1), ' ') << "*\n";
    }

    /* each iteration writes a " *" to the final row of the triangle, until the
     * row is filled in.  Invariant: we have written c columns of the row so
     * far.
     */
    std::cout << "*";
    for (int c = 1; c < 2 * tri_height - 1; c += 2) {
	std::cout << " *";
    }
    std::cout << "\n";

    return 0;
}
