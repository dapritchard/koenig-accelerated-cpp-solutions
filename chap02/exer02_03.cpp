/* Page 34
 *
 * Rewrite the framing program to ask the user to supply the amount of spacing
 * to leave between the frame and the greeting.
 */


#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin;         using std::endl;
using std::cout;        using std::string;


int main()
{
	// ask for the person's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;

	// ask for the number of blank characters to use for the height padding.
	// warning: does not check that a valid input is provided!
	cout << "Please enter a nonnegative integer for the height padding: ";
	unsigned int pad_height;
	cin >> pad_height;

	// ask for the number of blank characters to use for the width padding.
	// warning: does not check that a valid input is provided!
	cout << "Please enter a nonnegative integer for the width padding: ";
	unsigned int pad_width;
	cin >> pad_width;

	// build the message that we intend to write
	const string greeting = "Hello, " + name + "!";

	// the number of rows and columns to write
	const unsigned int rows = pad_height * 2 + 3;
	const string::size_type cols = greeting.size() + pad_width * 2 + 2;

	// write a blank line to separate the output from the input
	cout << endl;

	// write `rows' rows of output
	// invariant: we have written `r' rows so far
	for (unsigned int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		// invariant: we have written `c' characters so far in the current row
		while (c != cols) {

			// is it time to write the greeting?
			if (r == pad_height + 1 && c == pad_width + 1) {
				cout << greeting;
				c += greeting.size();
			} else {

				// are we on the border?
				if (r == 0 || r == rows - 1 ||
				    c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}

		cout << endl;
	}

	return 0;
}

