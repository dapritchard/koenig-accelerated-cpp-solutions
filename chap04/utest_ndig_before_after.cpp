#include <vector>
#include <string>
#include "../testing/UnitTest.h"
#include "calc_nchars.h"


class Test_ndig_before_after : public UnitTest {

public:

    void runTest() {

	int n_before, n_after;

	// assign arbitrary values to n_before and n_after
	n_before = n_after = 99999;
	
	// check for whole numbers
	ndig_before_after("1.000", &n_before, &n_after);
	UT_ASSERT(n_before == 1);
	UT_ASSERT(n_after == 0);

	// multiple digits before and after
	ndig_before_after("16.125", &n_before, &n_after);
	UT_ASSERT(n_before == 2);
	UT_ASSERT(n_after == 3);

	// negative number
	ndig_before_after("-1024.198400", &n_before, &n_after);
	UT_ASSERT(n_before == 5);
	UT_ASSERT(n_after == 4);
    }

};


int main() {

    Test_ndig_before_after test;
    test.runTest();

    return UnitTest::getNumFail();
}
