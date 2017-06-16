#include <iostream>
#include <vector>
#include <string>
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestCaller.h"
#include "cppunit/extensions/HelperMacros.h"
#include "stream_ext_palind.h"

using std::istringstream;
using std::vector;
using std::string;




class StreamExtPalindromeTest : public CppUnit::TestFixture {

private:
    
    istringstream *text;
    vector<string> *palindromes;
    string::size_type *maxlen;
    

public:

    void setUp() {

	text = new istringstream;
	palindromes = new vector<string>;
	maxlen = new string::size_type;
	
	text->str("gurgle stats Racecar paste blue RADAR wow test");

	palindromes->push_back("stats");
	palindromes->push_back("Racecar");
	palindromes->push_back("RADAR");
	palindromes->push_back("wow");

	*maxlen = 7;
    }

    
    void tearDown() {
	delete text;
	delete palindromes;
	delete maxlen;
    }


    void test_is_palindrome() {

	// blank or empty input is defined as a palindrome
	CPPUNIT_ASSERT(is_palindrome(""));
	// not palindrome
	CPPUNIT_ASSERT(! is_palindrome("abstract"));
	// yes palindrome
	CPPUNIT_ASSERT(is_palindrome("ROtatOR"));
	CPPUNIT_ASSERT(is_palindrome("!@12321@!"));
    }
    

    // test for empty data case
    void test_empty() {

	istringstream empty_stream;
	stream_ext_palind(empty_stream, *palindromes, *maxlen);

	// empty data case should clear the data in palindromes and return max
	// length of 0 by definition
	CPPUNIT_ASSERT(palindromes->empty());
	CPPUNIT_ASSERT(*maxlen == 0);
    }


    // test that palindromes are correctly extracted
    void test_palindromes() {

	vector<string> actual_pals;
	string::size_type actual_max;
	stream_ext_palind(*text, actual_pals, actual_max);

	// four palindromes in input data
	CPPUNIT_ASSERT(palindromes->size() == 4);

	// check each palindrome with targets
	CPPUNIT_ASSERT((*palindromes)[0] == actual_pals[0]);
	CPPUNIT_ASSERT((*palindromes)[1] == actual_pals[1]);
	CPPUNIT_ASSERT((*palindromes)[2] == actual_pals[2]);
	CPPUNIT_ASSERT((*palindromes)[3] == actual_pals[3]);
    }


    // test that the word length of the longest palindrome is correctly stored
    // in `maxlen'
    void test_maxlen() {

	vector<string> actual_pals;
	string::size_type actual_max;
	stream_ext_palind(*text, actual_pals, actual_max);

	// check maximum length
	CPPUNIT_ASSERT(*maxlen == actual_max);
    }


    CPPUNIT_TEST_SUITE(StreamExtPalindromeTest);
    CPPUNIT_TEST(test_is_palindrome);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST(test_palindromes);
    CPPUNIT_TEST(test_maxlen);
    CPPUNIT_TEST_SUITE_END();    
};




int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(StreamExtPalindromeTest::suite());

    return runner.run() ? 0 : 1;
}
