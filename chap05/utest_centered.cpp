#include <vector>
#include <string>
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestCaller.h"
#include <cppunit/extensions/HelperMacros.h>
#include "centered_picture.h"

using std::vector;
using std::string;
   



class CenteredTest : public CppUnit::TestFixture {

public:

    // test for empty data case
    void test_empty() {

	vector<string> empty_vec;
	vector<string> empty_frame;
	empty_frame.push_back("****");
	empty_frame.push_back("****");
	CPPUNIT_ASSERT(empty_frame == center(empty_vec));
    }

    
    // this case tests for non-even padding on the `two words' and `conclusion
    // lines
    void test_four() {

	vector<string> input;
	input.push_back("a phrase");
	input.push_back("");
	input.push_back("multiple words here");
	input.push_back("conclusion");
	
	vector<string> target;
	target.push_back("***********************");
	target.push_back("*      a phrase       *");
	target.push_back("*                     *");
	target.push_back("* multiple words here *");
	target.push_back("*     conclusion      *");
	target.push_back("***********************");

	vector<string> actual = center(input);
	CPPUNIT_ASSERT(target == actual);
    }

    CPPUNIT_TEST_SUITE( CenteredTest );
    CPPUNIT_TEST( test_empty );
    CPPUNIT_TEST( test_four );
    CPPUNIT_TEST_SUITE_END();    
};




int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(CenteredTest::suite());

    return runner.run() ? 0 : 1;
}
