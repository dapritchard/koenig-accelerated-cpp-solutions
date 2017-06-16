#include <iostream>
#include <vector>
#include <string>
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestCaller.h"
#include <cppunit/extensions/HelperMacros.h>
#include "stream_upp_seg.h"

using std::istringstream;
using std::vector;
using std::string;




class StreamUppSegTest : public CppUnit::TestFixture {

private:
    
    istringstream *text;
    vector<string> *low, *upp;
    

public:

    void setUp() {

	text = new istringstream;
	low = new vector<string>;
	upp = new vector<string>;
	
	text->str("Jack Straw from Wichita\nCut his buddy down");

	low->push_back("from");
	low->push_back("his");
	low->push_back("buddy");
	low->push_back("down");

	upp->push_back("Jack");
	upp->push_back("Straw");
	upp->push_back("Wichita");
	upp->push_back("Cut");
    }

    
    void tearDown() {
	delete text;
	delete low;
	delete upp;
    }


    void test_has_upper() {

	CPPUNIT_ASSERT(! has_upper("aabbccddee"));
	CPPUNIT_ASSERT(has_upper("aabbCCddee"));
    }
    

    // test for empty data case
    void test_empty() {

	istringstream empty_stream;
	vector<string> empty_low, empty_upp;
	stream_upp_seg(empty_stream, empty_low, empty_upp);

	CPPUNIT_ASSERT(empty_low.empty());
	CPPUNIT_ASSERT(empty_upp.empty());
    }


    // test that lowercase words are stored in the vector pointed to by the
    // argument to `lower'
    void test_low() {

	vector<string> actual_low, actual_upp;
	stream_upp_seg(*text, actual_low, actual_upp);

	CPPUNIT_ASSERT(*low == actual_low);
    }


    // test that words with an uppercase letter are stored in the vector pointed
    // to by the argument to `upper'
    void test_upp() {

	vector<string> actual_low, actual_upp;
	stream_upp_seg(*text, actual_low, actual_upp);

	CPPUNIT_ASSERT(*upp == actual_upp);
    }


    CPPUNIT_TEST_SUITE(StreamUppSegTest);
    CPPUNIT_TEST(test_has_upper);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST(test_low);
    CPPUNIT_TEST(test_upp);
    CPPUNIT_TEST_SUITE_END();    
};




int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(StreamUppSegTest::suite());

    return runner.run() ? 0 : 1;
}
