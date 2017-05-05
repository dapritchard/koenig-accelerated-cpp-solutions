/* Page 34
 *
 * The framing program writes the mostly blank lines that separate the borders
 * from the greeting one character at a time.  Change the program so that it
 * writes all the spaces needed in a single output expression.
 */


#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin;         using std::endl;
using std::cout;        using std::string;


int main() {
    
    // ask for the person's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    // ask for the number of blank characters to use for the height padding.
    // warning: does not check that a valid input is provided!
    cout << "Please enter a nonnegative integer for the height padding: ";
    int pad_height;
    cin >> pad_height;

    // ask for the number of blank characters to use for the width padding.
    // warning: does not check that a valid input is provided!
    cout << "Please enter a nonnegative integer for the width padding: ";
    int pad_width;
    cin >> pad_width;

    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // the number of rows and columns to write
    const int rows = pad_height * 2 + 3;
    const string::size_type cols = greeting.size() + pad_width * 2 + 2;

    // construct the rows we will be using
    const string star_row(cols, '*');
    const string pad_row = "*" + string(cols - 2, ' ') + "*";
    const string greet_row =
	"*" +
	string(pad_width, ' ') +
	greeting +
	string(pad_width, ' ') +
	"*";

    // write a blank line to separate the output from the input
    cout << endl;

    // write `rows' rows of output
    // invariant: we have written `r' rows so far
    for (int r = 0; r != rows; ++r) {

	// case: top or bottom of the frame
	if (r == 0 || r == rows - 1) {
	    cout << star_row << "\n";
	}
	// case: the greeting line
	else if (r ==  pad_height + 1) {
	    cout << greet_row << "\n";
	}
	// case: one of the padding rows
	else {
	    cout << pad_row << "\n";
	}
		
    }

    return 0;
}
