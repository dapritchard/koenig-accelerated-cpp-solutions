/* Page 7
 *
 * Write a program that, when run, writes the Hello, world! program as its
 * output.
 */

/* A more elegant way of answering this question would be to read the file
 * exer00_00.cpp and echo it to stdout.  But since we haven't learned how to do
 * this yet we'll just write the program line-by-line into the text of this
 * program.
 */

#include <iostream>


int main() {

    std::cout << "#include <iostream>\n"
	      << "\n"
	      << "int main() {\n"
	      << "    std::cout << \"Hello, world!\" << std::endl;\n"
	      << "    return 0;\n"
	      << "}\n";

    return 0;
}
