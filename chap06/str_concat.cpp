#include <vector>
#include <string>
#include <numeric>

using std::vector;
using std::string;


string str_concat(vector<string> v) {
    return accumulate(v.begin(), v.end(), string(""));
}
