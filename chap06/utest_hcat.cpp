#include <iostream>
#include <vector>
#include <string>
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestCaller.h"
#include "cppunit/extensions/HelperMacros.h"
#include "pics.h"

using std::vector;
using std::string;




class HcatTest : public CppUnit::TestFixture {

private:

    vector<string> *v1, *v2;

    
public:

    void setUp() {

	v1 = new vector<string>;
	v2 = new vector<string>;
	
	v1->push_back("Goin'");
	v1->push_back("down");
	v1->push_back("the");
	v1->push_back("road");
	v1->push_back("feelin'");
	v1->push_back("bad");

	v2->push_back("life");
	v2->push_back("is like a");
	v2->push_back("box of  ");
	v2->push_back("chocolates");
    }


    void tearDown() {
	delete v1;
	delete v2;
    }


    // check behavior for empty input
    void test_empty() {

	vector<string> empty0, empty1, out;

	CPPUNIT_ASSERT(hcat(empty0, empty1) == out);
    }
    

    // left side bigger
    void test_left_bigger() {

	vector<string> target;

	target.push_back("Goin'   life");
	target.push_back("down    is like a");
	target.push_back("the     box of  ");
	target.push_back("road    chocolates");
	target.push_back("feelin' ");
	target.push_back("bad     ");

	CPPUNIT_ASSERT(target == hcat(*v1, *v2));
    }
    

    // right side bigger
    void test_right_bigger() {

	vector<string> target;

	v1->resize(2);
	target.push_back("Goin' life");
	target.push_back("down  is like a");
	target.push_back("      box of  ");
	target.push_back("      chocolates");
	
	CPPUNIT_ASSERT(target == hcat(*v1, *v2));
    }
    

    CPPUNIT_TEST_SUITE(HcatTest);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST(test_left_bigger);
    CPPUNIT_TEST(test_right_bigger);
    CPPUNIT_TEST_SUITE_END();    
};




int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(HcatTest::suite());

    return runner.run() ? 0 : 1;
}
