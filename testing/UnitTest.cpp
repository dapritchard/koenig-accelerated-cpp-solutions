#include <cstdio>
#include "UnitTest.h"


// static variables to track the number of tests and successful tests
int UnitTest::num_test = 0;
int UnitTest::num_test_success = 0;


/* the result of a unit test is passed as `condition', and the function prints
 * out a message as to whether the test was successful or not.  Also increments
 * `num_test' and conditionally increments `num_test_success'.  Is intended to
 * be called through UT_ASSERT.
 */
void UnitTest::assertTrue(bool condition, const char *file,
			  int line, const char *msg) {

    if (condition) {
	printf("test %d:    success\n", num_test);
	++num_test_success;
    }
    else {
	printf("test %d:    *** FAILURE ***     %s:%d:%s\n",
	       num_test, file, line, msg);
    }

    ++num_test;
}
