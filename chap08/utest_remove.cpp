#include "lib_algs.h"
#include "utest_remove.h"

using std::vector;
typedef vector<char>::iterator vc_iter;


bool RemoveTest::is_a(char c) {
    return (c == 'a');
}


void RemoveTest::setUp() {
    vec = new vector<char>;    
    vec->push_back('a'); vec->push_back('b'); vec->push_back('a'); vec->push_back('c');
}


void RemoveTest::tearDown() {
    delete vec;
}


// if `beg1' and `end1' are equal then by definition `my_copy' returns `dest'
void RemoveTest::test_equal_iters() {
    
    vc_iter actual_val = my_remove(vec->begin(), vec->begin(), 'a');
    vc_iter actual_pred = my_remove_if(vec->begin(), vec->begin(), is_a);
    
    CPPUNIT_ASSERT(actual_val == vec->begin());
    CPPUNIT_ASSERT(actual_pred == vec->begin());
}


// test remove procedure for value-based version
void RemoveTest::test_remove_val() {
    
    vc_iter actual_val = my_remove(vec->begin(), vec->end(), 'a');
    
    CPPUNIT_ASSERT(actual_val == vec->begin() + 2);

    CPPUNIT_ASSERT((*vec)[0] == 'b');
    CPPUNIT_ASSERT((*vec)[1] == 'c');
}


// test remove procedure for predicate-based version
void RemoveTest::test_remove_pred() {
    
    vc_iter actual_pred = my_remove(vec->begin(), vec->end(), 'a');
    
    CPPUNIT_ASSERT(actual_pred == vec->begin() + 2);

    CPPUNIT_ASSERT((*vec)[0] == 'b');
    CPPUNIT_ASSERT((*vec)[1] == 'c');
}
