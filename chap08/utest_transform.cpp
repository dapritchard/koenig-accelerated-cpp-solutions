#include "lib_algs.h"
#include "utest_transform.h"

using std::vector;
typedef vector<int>::iterator vc_iter;


int TransformTest::twice(int k) {
    return 2 * k;
}


int TransformTest::product(int r, int s) {
    return r * s;
}


void TransformTest::setUp() {
    
    v1 = new vector<int>;
    v2 = new vector<int>;
    dest_a = new vector<int>;
    dest_b = new vector<int>;
    
    v1->push_back(1); v1->push_back(3); v1->push_back(6); v1->push_back(-2);
    v2->push_back(3); v2->push_back(-2); v2->push_back(4); v2->push_back(9);
    
    dest_a->resize(4);
    dest_b->resize(4);
}


void TransformTest::tearDown() {
    delete v1;
    delete v2;
    delete dest_a;
}


// if `beg1' and `end1' are equal then by definition `my_transform' returns `dest_a'
void TransformTest::test_equal_iters() {
    
    vc_iter actual_un = my_transform(v1->begin(), v1->begin(), dest_a->begin(), twice);
    vc_iter actual_bi = my_transform(v1->begin(), v1->begin(), v2->begin(), dest_b->begin(), product);

    CPPUNIT_ASSERT(actual_un == dest_a->begin());
    CPPUNIT_ASSERT(actual_bi == dest_b->begin());
}


// if the value denoted by `val' occurs in the range denoted by the iterators in
// `v1', then return an iterator positioned on the first occurrence in the
// sequence in `v1'
void TransformTest::test_transform() {

    vector<int> v1_orig = *v1;
    vector<int> v2_orig = *v2;
    
    vc_iter actual_un = my_transform(v1->begin(), v1->end(), dest_a->begin(), twice);
    vc_iter actual_bi = my_transform(v1->begin(), v1->end(), v2->begin(), dest_b->begin(), product);

    // check return values
    CPPUNIT_ASSERT(actual_un == dest_a->begin() + 4);
    CPPUNIT_ASSERT(actual_bi == dest_b->begin() + 4);

    // v1, v2 should be unchanged
    CPPUNIT_ASSERT(*v1 == v1_orig);
    CPPUNIT_ASSERT(*v2 == v2_orig);

    // values should be doubled from v1
    CPPUNIT_ASSERT((*dest_a)[0] == 2);
    CPPUNIT_ASSERT((*dest_a)[1] == 6);
    CPPUNIT_ASSERT((*dest_a)[2] == 12);
    CPPUNIT_ASSERT((*dest_a)[3] == -4);

    // values should be the pairwise products from v1 and v2
    CPPUNIT_ASSERT((*dest_b)[0] == 3);
    CPPUNIT_ASSERT((*dest_b)[1] == -6);
    CPPUNIT_ASSERT((*dest_b)[2] == 24);
    CPPUNIT_ASSERT((*dest_b)[3] == -18);
}
