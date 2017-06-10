#include <vector>
#include <stdexcept>
#include "../testing/UnitTest.h"
#include "vec_dbl_ave.h"

using std::vector;




class Test_vec_dbl_ave : public UnitTest {

public:

    void runTest() {

	// test empty stream
	vector<double> empty_vec;
	UT_ASSERT_THROW(vec_dbl_ave(empty_vec), std::invalid_argument);

	// test the average of 1, 2, ..., 10
	vector<double> vals;
	vals.push_back(1); vals.push_back(2); vals.push_back(3); vals.push_back(4);
	vals.push_back(5); vals.push_back(6); vals.push_back(7); vals.push_back(8);
	vals.push_back(9); vals.push_back(10);
	UT_ASSERT(vec_dbl_ave(vals) == 5.5);
	
    }

};




int main() {

    Test_vec_dbl_ave test;
    test.runTest();

    return UnitTest::getNumFail();
}
