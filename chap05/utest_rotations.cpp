#include <vector>
#include <string>
#include "../testing/UnitTest.h"
#include "rotations.h"

using std::vector;
using std::string;




class Test_rotations : public UnitTest {

public:

    void runTest() {

	// test empty input vector, empty storage container
	vector<string> empty_vec;
	vector<permute_pair> empty_out;
	rotations(empty_vec, empty_out);
	UT_ASSERT(empty_out.empty());

	// test 1-word input vector, empty storage container
	vector<permute_pair> one_out;
	vector<string> one_word;
	one_word.push_back("C++");
	rotations(one_word, one_out);
	UT_ASSERT(one_out[0].phrase == "");
	UT_ASSERT(one_out[0].index == "C++");

	// test 1-word input vector, non-empty storage container
	permute_pair testpair = { "", "OOP" };
	vector<permute_pair> nonempty;
	nonempty.push_back(testpair);
	one_word.clear();
	one_word.push_back("C++");
	rotations(one_word, nonempty);
	UT_ASSERT(nonempty[0].phrase == "");
	UT_ASSERT(nonempty[0].index == "OOP");
	UT_ASSERT(nonempty[1].phrase == "");
	UT_ASSERT(nonempty[1].index == "C++");

	/* test all rotations for a four-word input vector, empty storage
	 * container
	 */
	vector<string> words;
	words.push_back("burn");
	words.push_back("the");
	words.push_back("midnight");
	words.push_back("oil");
	vector<permute_pair> rota_pairs;
	rotations(words, rota_pairs);
	
	UT_ASSERT(rota_pairs[0].phrase == "");
	UT_ASSERT(rota_pairs[0].index == "burn the midnight oil");
	
	UT_ASSERT(rota_pairs[1].phrase == "burn");
	UT_ASSERT(rota_pairs[1].index == "the midnight oil");
	
	UT_ASSERT(rota_pairs[2].phrase == "burn the");
	UT_ASSERT(rota_pairs[2].index == "midnight oil");
	
	UT_ASSERT(rota_pairs[3].phrase == "burn the midnight");
	UT_ASSERT(rota_pairs[3].index == "oil");


    }

};




int main() {

    Test_rotations test;
    test.runTest();

    return UnitTest::getNumFail();
}
