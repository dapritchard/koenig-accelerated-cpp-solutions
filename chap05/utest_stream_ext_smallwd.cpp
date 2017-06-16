#include <iostream>
#include <vector>
#include <string>
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestCaller.h"
#include "cppunit/extensions/HelperMacros.h"
#include "stream_ext_smallwd.h"

using std::istringstream;
using std::vector;
using std::string;




class StreamExtSmallwdTest : public CppUnit::TestFixture {

private:
    
    istringstream *text;
    vector<string> *small_words;
    string::size_type *maxlen;
    

public:

    void setUp() {

	text = new istringstream;
	small_words = new vector<string>;
	maxlen = new string::size_type;
	
	text->str("God save the child who rings that bell\n"
		  "I may have one good ring baby, you can't tell");

	small_words->push_back("save");
	small_words->push_back("one");

	*maxlen = 4;
    }

    
    void tearDown() {
	delete text;
	delete small_words;
	delete maxlen;
    }


    // test predicate function for words without either ascenders or descenders
    void test_is_smallwd() {

	// blank or empty input is defined as a small word
	CPPUNIT_ASSERT(is_smallwd(""));
	// not small word
	CPPUNIT_ASSERT(! is_smallwd("bdfghijklpqty"));
	CPPUNIT_ASSERT(! is_smallwd("I"));
	CPPUNIT_ASSERT(! is_smallwd("UFO"));
	CPPUNIT_ASSERT(! is_smallwd("man!"));
	// yes small word
	CPPUNIT_ASSERT(is_smallwd("acemnorsuvwxz"));
    }
    

    // test for empty data case
    void test_empty() {

	istringstream empty_stream;
	stream_ext_smallwd(empty_stream, *small_words, *maxlen);

	// empty data case should clear the data in `small_words' and return max
	// length of 0 by definition
	CPPUNIT_ASSERT(small_words->empty());
	CPPUNIT_ASSERT(*maxlen == 0);
    }


    // test that words without either an ascender or a descender are correctly
    // extracted
    void test_small_words() {

	vector<string> actual_smallwd;
	string::size_type actual_max;
	stream_ext_smallwd(*text, actual_smallwd, actual_max);

	// four small_words in input data
	CPPUNIT_ASSERT(small_words->size() == 2);

	// check each small word with targets
	CPPUNIT_ASSERT((*small_words)[0] == actual_smallwd[0]);
	CPPUNIT_ASSERT((*small_words)[1] == actual_smallwd[1]);
    }



    // test that the word length of the longest word without either an ascender
    // or a descender is correctly stored in `maxlen'
    void test_maxlen() {

	vector<string> actual_smallwd;
	string::size_type actual_max;
	stream_ext_smallwd(*text, actual_smallwd, actual_max);

	// check maximum length
	CPPUNIT_ASSERT(*maxlen == actual_max);
    }


    CPPUNIT_TEST_SUITE(StreamExtSmallwdTest);
    CPPUNIT_TEST(test_is_smallwd);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST(test_small_words);
    CPPUNIT_TEST(test_maxlen);
    CPPUNIT_TEST_SUITE_END();    
};




int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(StreamExtSmallwdTest::suite());

    return runner.run() ? 0 : 1;
}
