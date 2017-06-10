#include <vector>
#include <stdexcept>
#include "../testing/UnitTest.h"
#include "calc_seq.h"


class Test_calc_seq : public UnitTest {

public:

    void runTest() {

	// from = -1, to = 1, by = 0.2
	std::vector<double> vec0;
	for (double curr = 0.0; curr <= 1.0; curr += 0.2) {
	    vec0.push_back(curr);
	}

	// from = 0, to = 0.95, by = 0.2
	std::vector<double> vec1;
	for (double curr = 0.0; curr <= 0.95; curr += 0.2) {
	    vec1.push_back(curr);
	}

	// from = 0, to = 1, by = 999 (i.e. length 0 vector)
	std::vector<double> vec2;
	for (double curr = 0.0; curr <= 1.0; curr += 999.0) {
	    vec2.push_back(curr);
	}

	// from = 0, to = 0, by = 1
	std::vector<double> vec3;
	for (double curr = 0.0; curr <= 0.0; curr += 1.0) {
	    vec3.push_back(curr);
	}

	// valid sequence
    	UT_ASSERT(vec0 == calc_seq(0.0, 1.0, 0.2));
	// `by' doesn't evenly divide `from' - `to'
    	UT_ASSERT(vec1 == calc_seq(0.0, 0.95, 0.2));
	// sequence of length 0
    	UT_ASSERT(vec2 == calc_seq(0.0, 1.0, 999.0));
	// `from' == `to'
    	UT_ASSERT(vec3 == calc_seq(0.0, 0.0, 1.0));
	// `from' > `to'
	UT_ASSERT_THROW(calc_seq(1.0, 0.0, 1.0), std::invalid_argument);
	// `by' == 0
	UT_ASSERT_THROW(calc_seq(0.0, 1.0, 0.0), std::invalid_argument);
	// `by' < 0
	UT_ASSERT_THROW(calc_seq(0.0, 1.0, -1.0), std::invalid_argument);

    }

};


int main() {

    Test_calc_seq test;
    test.runTest();

    return UnitTest::getNumFail();
}
