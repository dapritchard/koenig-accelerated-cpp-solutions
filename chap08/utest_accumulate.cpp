#include "lib_algs.h"
#include "utest_accumulate.h"

using std::vector;
typedef vector<int>::iterator vc_iter;


void AccumulateTest::setUp() {
    vec = new vector<int>;
    vec->push_back(1); vec->push_back(2); vec->push_back(3); vec->push_back(4);
    vec->push_back(5); vec->push_back(6); vec->push_back(7); vec->push_back(8);
}


void AccumulateTest::tearDown() {
    delete vec;
}


// test that the return value for to equal iterators is the same as the
// value passed in
void AccumulateTest::test_equal_iters() {
    CPPUNIT_ASSERT(my_accumulate(vec->begin(), vec->begin(), 100) == 100);
}



// test the accumulate functionality
void AccumulateTest::test_accumulate() {
    CPPUNIT_ASSERT(my_accumulate(vec->begin(), vec->end(), 100) == 136);
}
