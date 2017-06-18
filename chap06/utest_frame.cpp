#include <iostream>
#include <vector>
#include <string>
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestCaller.h"
#include "cppunit/extensions/HelperMacros.h"
#include "pics.h"

using std::vector;
using std::string;




class FrameTest : public CppUnit::TestFixture {

public:

    // check behavior for empty input
    void test_empty() {

	vector<string> empty;
	vector<string> out;
	out.push_back("****");
	out.push_back("****");

	// check that empty input is handled reasonably
	CPPUNIT_ASSERT(frame(empty) == out);
    }
    

    // test with a length-4 vector
    void test_multiple() {

	vector<string> input, target;

	input.push_back("a frame");
	input.push_back("is a   ");
	input.push_back("box of");
	input.push_back("asterisks");

	target.push_back("*************");
	target.push_back("* a frame   *");
	target.push_back("* is a      *");
	target.push_back("* box of    *");
	target.push_back("* asterisks *");
	target.push_back("*************");

	CPPUNIT_ASSERT(frame(input) == target);
    }
    

    CPPUNIT_TEST_SUITE(FrameTest);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST(test_multiple);
    CPPUNIT_TEST_SUITE_END();    
};




int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(FrameTest::suite());

    return runner.run() ? 0 : 1;
}
