#include "lib_algs.h"
#include "utest_search.h"

using std::vector;
typedef vector<char>::iterator vc_iter;


void SearchTest::setUp() {
    v1 = new vector<char>;
    v2 = new vector<char>;
    
    v1->push_back('m'); v1->push_back('n'); v1->push_back('a'); v1->push_back('b');
    v1->push_back('q'); v1->push_back('r'); v1->push_back('j'); v1->push_back('a');
    v1->push_back('b'); v1->push_back('c'); v1->push_back('g'); v1->push_back('f'); 

    v2->push_back('a'); v2->push_back('b'); v2->push_back('c');
}


void SearchTest::tearDown() {
    delete v1;
    delete v2;
}


// if `beg1' and `end1' are equal then by definition `my_search' returns `end1'
void SearchTest::test_equal_first_iters() {
    
    vc_iter actual = my_search(v1->begin(), v1->begin(), v2->begin(), v2->end());
    CPPUNIT_ASSERT(actual == v1->begin());
}


// if `beg2' and `end2' are equal then by definition `my_search' returns `beg1'
void SearchTest::test_equal_second_iters() {

    vc_iter actual = my_search(v1->begin(), v1->end(), v2->begin(), v2->begin());
    CPPUNIT_ASSERT(actual == v1->begin());
}


// if the sequence denoted by the range between the iterators in `v2' occurs in
// the range denoted by the iterators in `v1', then return an iterator
// positioned on the first position in the first occurrence in the sequence in
// `v1'
void SearchTest::test_exists_seq() {
    
    vc_iter actual = my_search(v1->begin(), v1->end(), v2->begin(), v2->end());
    CPPUNIT_ASSERT(actual == v1->begin() + 7);
}


// if the sequence denoted by the range between the iterators in `v2' does not
// occur in the range denoted by the iterators in `v1', then return `end1'
void SearchTest::test_doesnt_exist_seq() {

    // cut off the range before a match can be made
    vc_iter cutoff_end = v1->end() - 3;
    
    vc_iter actual = my_search(v1->begin(), cutoff_end, v2->begin(), v2->end());
    CPPUNIT_ASSERT(actual == cutoff_end);
}
