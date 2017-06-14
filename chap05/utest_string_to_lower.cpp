#include <vector>
#include <string>
#include "../testing/UnitTest.h"
#include "rotations.h"

using std::vector;
using std::string;




class Test_string_to_lower : public UnitTest {

public:

    void runTest() {

	// empty string
	string empty;
	UT_ASSERT(string_to_lower(empty).empty());

	// length-0 string
	UT_ASSERT(string_to_lower("") == "");

	// mixed case string
	UT_ASSERT(string_to_lower("AaBb 123 Cc 456 ^&* Dd") == "aabb 123 cc 456 ^&* dd");

    }

};




int main() {

    Test_string_to_lower test;
    test.runTest();

    return UnitTest::getNumFail();
}
