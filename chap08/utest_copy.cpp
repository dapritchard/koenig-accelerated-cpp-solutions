#include "lib_algs.h"
#include "utest_copy.h"

using std::vector;
typedef vector<char>::iterator vc_iter;


void CopyTest::setUp() {
    
    v1 = new vector<char>;
    v2 = new vector<char>;
    
    v1->push_back('a'); v1->push_back('b'); v1->push_back('c'); v1->push_back('d');
    v2->push_back('w'); v2->push_back('x'); v2->push_back('y'); v2->push_back('z');
}


void CopyTest::tearDown() {
    delete v1;
    delete v2;
}


// if `beg1' and `end1' are equal then by definition `my_copy' returns `dest'
void CopyTest::test_equal_iters() {
    
    vc_iter actual = my_copy(v1->begin(), v1->begin(), v2->begin());
    CPPUNIT_ASSERT(actual == v2->begin());
}


// test copy procedure
void CopyTest::test_copy() {
    
    vc_iter actual = my_copy(v1->begin() + 1, v1->begin() + 3, v2->begin() + 2);
    
    CPPUNIT_ASSERT(actual == v2->begin() + 4);
    CPPUNIT_ASSERT(v2->size() == 4);

    CPPUNIT_ASSERT((*v2)[0] == 'w');
    CPPUNIT_ASSERT((*v2)[1] == 'x');
    CPPUNIT_ASSERT((*v2)[2] == 'b');
    CPPUNIT_ASSERT((*v2)[3] == 'c');
}
