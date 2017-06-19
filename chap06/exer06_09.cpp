#include <iostream>
#include <vector>
#include <string>
#include "str_concat.h"

using std::cout;
using std::vector;
using std::string;


int main() {

    vector<string> phrase;

    phrase.push_back("to ");
    phrase.push_back("thine ");
    phrase.push_back("own ");
    phrase.push_back("self ");
    phrase.push_back("be ");
    phrase.push_back("true");

    cout << str_concat(phrase) << "\n";

    return 0;
}
