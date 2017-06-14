/* Page 100
 *
 * Write a function named center(const vector<string>&) that returns a picture
 * in which all the lines of the original picture are padded out to their full
 * width, and the padding is as evenly divided as possible between the left and
 * right sides of the picture.  What are the properties of pictures for which
 * such a function is useful?  How can you tell whether a given picture has
 * those properties?
 */

#include <iostream>
#include <vector>
#include <string>
#include "centered_picture.h"

using std::cout;
using std::vector;
using std::string;


int main() {

    // construct input
    vector<string> example;
    example.push_back("");
    example.push_back("a");
    example.push_back("bb");
    example.push_back("ccc");
    example.push_back("dddd");
    example.push_back("eeeee");
    example.push_back("ffffff");
    example.push_back("ggggggg");

    // construct centered picture
    vector<string> centered_picture = center(example);

    // write picture to stdout line-by-line
    for (vector<string>::const_iterator curr = centered_picture.begin();
	 curr != centered_picture.end();
	 curr++) {
	
	cout << *curr << "\n";
    }

    return 0;
}
