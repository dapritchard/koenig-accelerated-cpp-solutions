#include "lib_algs.h"
#include "utest_partition.h"

using std::vector;
typedef vector<int>::iterator vc_iter;


bool PartitionTest::is_neg(int k) {
    return k < 0;
}


void PartitionTest::setUp() {
    
    all_neg = new vector<int>;
    all_pos = new vector<int>;
    mixed = new vector<int>;
    
    all_neg->push_back(-4); all_neg->push_back(-3); all_neg->push_back(-2); all_neg->push_back(-1);

    all_pos->push_back( 1); all_pos->push_back( 2); all_pos->push_back( 3); all_pos->push_back( 4);
    
    mixed->push_back( 1); mixed->push_back(-4); mixed->push_back( 2); mixed->push_back( 3);
    mixed->push_back(-3); mixed->push_back( 4); mixed->push_back(-2); mixed->push_back(-1);
}


void PartitionTest::tearDown() {
    delete all_neg;
    delete all_pos;
    delete mixed;
}


// test that the return value for to equal iterators is the same as the
// iterators
void PartitionTest::test_equal_iters() {
    CPPUNIT_ASSERT(my_partition(all_neg->begin(), all_neg->begin(), is_neg) == all_neg->begin());
}



// test that a container of elements that all evaluate to true returns an
// iterator pointing to one past the last element in the range, and the elements
// are unchanged
void PartitionTest::test_all_true() {

    vector<int> orig_all_neg;
    vc_iter out_iter;

    orig_all_neg = *all_neg;
    out_iter = my_partition(all_neg->begin(), all_neg->end(), is_neg);

    // 
    CPPUNIT_ASSERT(out_iter == all_neg->end());
    CPPUNIT_ASSERT(*all_neg == orig_all_neg);
}


// test that a container of elements that all evaluate to false returns an
// iterator pointing to the first element in the range, and the elements are unchanged
void PartitionTest::test_all_false() {

    vector<int> orig_all_pos;
    vc_iter out_iter;

    orig_all_pos = *all_pos;
    out_iter = my_partition(all_pos->begin(), all_pos->end(), is_neg);

    // 
    CPPUNIT_ASSERT(out_iter == all_pos->begin());
    CPPUNIT_ASSERT(*all_pos == orig_all_pos);
}


// check that a mixed ordering of elements are properly separated
void PartitionTest::test_mixed() {
    
    vc_iter out_iter, curr;

    out_iter = my_partition(mixed->begin(), mixed->end(), is_neg);
    curr = mixed->begin();

    CPPUNIT_ASSERT(out_iter - curr == 4);
    CPPUNIT_ASSERT(is_neg(*curr++));
    CPPUNIT_ASSERT(is_neg(*curr++));
    CPPUNIT_ASSERT(is_neg(*curr++));
    CPPUNIT_ASSERT(is_neg(*curr++));
    CPPUNIT_ASSERT(! is_neg(*curr++));
    CPPUNIT_ASSERT(! is_neg(*curr++));
    CPPUNIT_ASSERT(! is_neg(*curr++));
    CPPUNIT_ASSERT(! is_neg(*curr++));
}
