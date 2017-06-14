#include <sstream>
#include <vector>
#include <string>
#include "../testing/UnitTest.h"
#include "rotations.h"

using std::vector;
using std::string;
using std::istringstream;



class Test_stream_to_rotations : public UnitTest {

public:

    void runTest() {

	// test empty stream
	istringstream emptystream("");
	UT_ASSERT(stream_to_rotations(emptystream).empty());

	// test two line stream
	istringstream two_lines("burn the midnight oil\na hot potato");
	vector<permute_pair> rotats = stream_to_rotations(two_lines);

	UT_ASSERT(rotats[0].phrase == "");
	UT_ASSERT(rotats[0].index == "burn the midnight oil");
	
	UT_ASSERT(rotats[1].phrase == "burn");
	UT_ASSERT(rotats[1].index == "the midnight oil");
	
	UT_ASSERT(rotats[2].phrase == "burn the");
	UT_ASSERT(rotats[2].index == "midnight oil");
	
	UT_ASSERT(rotats[3].phrase == "burn the midnight");
	UT_ASSERT(rotats[3].index == "oil");
	
	UT_ASSERT(rotats[4].phrase == "");
	UT_ASSERT(rotats[4].index == "a hot potato");
	
	UT_ASSERT(rotats[5].phrase == "a");
	UT_ASSERT(rotats[5].index == "hot potato");
	
	UT_ASSERT(rotats[6].phrase == "a hot");
	UT_ASSERT(rotats[6].index == "potato");

    }

};




int main() {

    Test_stream_to_rotations test;
    test.runTest();

    return UnitTest::getNumFail();
}
