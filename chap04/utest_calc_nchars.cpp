#include "../testing/UnitTest.h"
#include "calc_nchars.h"


class Test_calc_nchars : public UnitTest {

public:

    void runTest() {
	
	UT_ASSERT(calc_nchars(0) == 1);
	UT_ASSERT(calc_nchars(1) == 1);
	UT_ASSERT(calc_nchars(10) == 2);
	UT_ASSERT(calc_nchars(123456) == 6);
	UT_ASSERT(calc_nchars(-9) == 2);
	UT_ASSERT(calc_nchars(-19) == 3);
	UT_ASSERT(calc_nchars(-8765) == 5);
    }

};


int main() {

    Test_calc_nchars test;
    test.runTest();

    return UnitTest::getNumFail();
}
