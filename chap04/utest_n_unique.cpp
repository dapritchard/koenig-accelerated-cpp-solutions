#include <vector>
#include <string>
#include "../testing/UnitTest.h"
#include "count_unique_in_stream.h"

using std::vector;
using std::string;




class Test_n_unique : public UnitTest {

public:

    void runTest() {

	// test empty vector
	vector<string> empty_in, empty_out;
	vector<int> empty_wcount;
	n_unique(empty_in, empty_out, empty_wcount);
	UT_ASSERT(empty_out.size() == 0);
	UT_ASSERT(empty_wcount.size() == 0);

	// test a string vector with multiple duplicates
	vector<string> input_vec;
	vector<string> unique_vec;
	vector<int> wcount_vec;
	input_vec.push_back("Ritchie");
	input_vec.push_back("Thompson");
	input_vec.push_back("Stroustrup");
	input_vec.push_back("Ritchie");
	input_vec.push_back("Stroustrup");
	input_vec.push_back("Ritchie");
	n_unique(input_vec, unique_vec, wcount_vec);
	UT_ASSERT(unique_vec[0] == "Ritchie");
	UT_ASSERT(unique_vec[1] == "Thompson");
	UT_ASSERT(unique_vec[2] == "Stroustrup");
	UT_ASSERT(unique_vec.size() == 3);
	UT_ASSERT(wcount_vec[0] == 3);
	UT_ASSERT(wcount_vec[1] == 1);
	UT_ASSERT(wcount_vec[2] == 2);
	UT_ASSERT(wcount_vec.size() == 3);
	
    }

};




int main() {

    Test_n_unique test;
    test.runTest();

    return UnitTest::getNumFail();
}
