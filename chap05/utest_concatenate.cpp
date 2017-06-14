#include <vector>
#include <string>
#include "../testing/UnitTest.h"
#include "rotations.h"

using std::vector;
using std::string;




class Test_concatenate : public UnitTest {

public:

    void runTest() {

	vector<string> words;
	words.push_back("burn");
	words.push_back("the");
	words.push_back("midnight");
	words.push_back("oil");

	vector<string>::const_iterator begin;
	vector<string>::const_iterator end;

	// test concatenating the whole vector
	UT_ASSERT(concatenate(words, words.begin(), words.end()) == "burn the midnight oil");

	// test first word
	UT_ASSERT(concatenate(words, words.begin(), words.begin() += 1) == "burn");

	// test middle words
	UT_ASSERT(concatenate(words, words.begin() += 1, words.begin() += 3) == "the midnight");

	// test no words
	UT_ASSERT(concatenate(words, words.begin(), words.begin()) == "");

	// test empty string
	vector<string> empty;
	UT_ASSERT(concatenate(empty, empty.begin(), empty.end()) == "");

	
    }

};




int main() {

    Test_concatenate test;
    test.runTest();

    return UnitTest::getNumFail();
}
