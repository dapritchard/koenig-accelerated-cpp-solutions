#include "lib_algs.h"
#include "utest_find.h"

using std::vector;
typedef vector<char>::iterator vc_iter;


bool FindTest::is_d(char c) {
    return c == 'd';
}


bool FindTest::is_z(char c) {
    return c == 'z';
}


void FindTest::setUp() {
    vec = new vector<char>;    
    vec->push_back('a'); vec->push_back('b'); vec->push_back('c'); vec->push_back('d'); 
}


void FindTest::tearDown() {
    delete vec;
}


// if `beg1' and `end1' are equal then by definition `my_find' returns `end1'
void FindTest::test_equal_iters() {
    
    vc_iter actual_val = my_find(vec->begin(), vec->begin(), 'c');
    vc_iter actual_pred = my_find_if(vec->begin(), vec->begin(), is_d);

    CPPUNIT_ASSERT(actual_val == vec->begin());
    CPPUNIT_ASSERT(actual_pred == vec->begin());
}


// if the value denoted by `val' occurs in the range denoted by the iterators in
// `vec', then return an iterator positioned on the first occurrence in the
// sequence in `vec'
void FindTest::test_exists() {
    
    vc_iter actual_val = my_find(vec->begin(), vec->end(), 'c');
    vc_iter actual_pred = my_find_if(vec->begin(), vec->end(), is_d);
    
    CPPUNIT_ASSERT(actual_val == vec->begin() + 2);
    CPPUNIT_ASSERT(actual_pred == vec->begin() + 3);
}


// if the value denoted by `val' does not occur in the range denoted by the
// iterators in `vec', then return `end'
void FindTest::test_doesnt_exist() {

    vc_iter actual_val = my_find(vec->begin(), vec->end(), 'z');
    vc_iter actual_pred = my_find_if(vec->begin(), vec->end(), is_z);
    
    CPPUNIT_ASSERT(actual_val == vec->end());
    CPPUNIT_ASSERT(actual_pred == vec->end());
}
