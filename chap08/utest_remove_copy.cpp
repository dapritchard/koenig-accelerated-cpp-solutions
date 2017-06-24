#include "lib_algs.h"
#include "utest_remove_copy.h"

using std::vector;
typedef vector<char>::iterator vc_iter;


bool RemoveCopyTest::is_a(char c) {
    return (c == 'a');
}


void RemoveCopyTest::setUp() {
    
    v1 = new vector<char>;
    v2 = new vector<char>;
    
    v1->push_back('a'); v1->push_back('b'); v1->push_back('a'); v1->push_back('c');
    v2->push_back('x'); v2->push_back('x'); v2->push_back('x'); v2->push_back('x');
}


void RemoveCopyTest::tearDown() {
    delete v1;
    delete v2;
}


// if `beg1' and `end1' are equal then by definition `my_copy' returns `dest'
void RemoveCopyTest::test_equal_iters() {
    
    vc_iter actual = my_remove_copy(v1->begin(), v1->begin(), v2->begin(), 'a');
    CPPUNIT_ASSERT(actual == v2->begin());
}


// test copy procedure
void RemoveCopyTest::test_copy_val() {
    
    vc_iter actual = my_remove_copy(v1->begin(), v1->end(), v2->begin(), 'a');
    
    CPPUNIT_ASSERT(actual == v2->begin() + 2);
    CPPUNIT_ASSERT(v2->size() == 4);

    CPPUNIT_ASSERT((*v2)[0] == 'b');
    CPPUNIT_ASSERT((*v2)[1] == 'c');
    CPPUNIT_ASSERT((*v2)[2] == 'x');
    CPPUNIT_ASSERT((*v2)[3] == 'x');
}


// test copy procedure
void RemoveCopyTest::test_copy_pred() {
    
    vc_iter actual = my_remove_copy_if(v1->begin(), v1->end(), v2->begin(), is_a);
    
    CPPUNIT_ASSERT(actual == v2->begin() + 2);
    CPPUNIT_ASSERT(v2->size() == 4);

    CPPUNIT_ASSERT((*v2)[0] == 'b');
    CPPUNIT_ASSERT((*v2)[1] == 'c');
    CPPUNIT_ASSERT((*v2)[2] == 'x');
    CPPUNIT_ASSERT((*v2)[3] == 'x');
}
