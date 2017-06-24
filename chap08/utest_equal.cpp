#include "lib_algs.h"
#include "utest_equal.h"

using std::vector;


void EqualTest::setUp() {
    v1 = new vector<int>;
    v2 = new vector<int>;
    v1->push_back(1); v1->push_back(2); v1->push_back(3); 
    v2->push_back(1); v2->push_back(2); v2->push_back(3); v2->push_back(4);
}


void EqualTest::tearDown() {
    delete v1;
    delete v2;
}


// if `beg1' and `beg2' are equal then by definition `my_equal' returns true
void EqualTest::test_equal_iters() {
    CPPUNIT_ASSERT( my_equal(v1->begin(), v1->begin(), v2->begin()) );
}


// return true if two vecs are equal in the range
void EqualTest::test_equal_vecs() {
    CPPUNIT_ASSERT( my_equal(v1->begin(), v1->end(), v2->begin()) );
}


// return false if two vecs are not equal in the range
void EqualTest::test_not_equal_vecs() {
    (*v1)[2] = 99;
    CPPUNIT_ASSERT(! my_equal(v1->begin(), v1->end(), v2->begin()));
}
