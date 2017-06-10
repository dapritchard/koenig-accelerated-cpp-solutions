#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "../testing/UnitTest.h"
#include "count_unique_in_stream.h"

using std::vector;
using std::string;
using std::istringstream;
using std::ostringstream;




class Test_stream_to_words : public UnitTest {

public:

    void runTest() {

	// dummy output stream to suppress writing to stdout
	ostringstream dummystream;

	// test empty stream
	istringstream emptystream("");
	vector<string> empty_vec;
	UT_ASSERT(stream_to_words(emptystream, dummystream) == empty_vec);

	// test a 3-token stream
	istringstream inputstream("my test string");
	vector<string> target_vec;
	target_vec.push_back("my");
	target_vec.push_back("test");
	target_vec.push_back("string");
	UT_ASSERT(stream_to_words(inputstream, dummystream) == target_vec);
	
    }

};




int main() {

    Test_stream_to_words test;
    test.runTest();

    return UnitTest::getNumFail();
}
