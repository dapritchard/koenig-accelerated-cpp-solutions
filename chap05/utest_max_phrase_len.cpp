#include <vector>
#include <string>
#include "../testing/UnitTest.h"
#include "rotations.h"

using std::vector;



class Test_max_phrase_len : public UnitTest {

public:

    void runTest() {

	// test empty vector
	vector<permute_pair> empty;
	UT_ASSERT(max_phrase_len(empty) == 0);

	// test length-4 vector
	permute_pair entry;
	vector<permute_pair> test_vec;
	
	entry.phrase = "a";
	test_vec.push_back(entry);
	
	entry.phrase = "bb";
	test_vec.push_back(entry);
	
	entry.phrase = "ccc";
	test_vec.push_back(entry);
	
	entry.phrase = "dddd";
	test_vec.push_back(entry);
	
	UT_ASSERT(max_phrase_len(test_vec) == 4);
	
    }

};




int main() {

    Test_max_phrase_len test;
    test.runTest();

    return UnitTest::getNumFail();
}
