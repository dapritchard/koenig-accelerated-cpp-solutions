#ifndef CHAP08_UTEST_TRANSFORM_H_
#define CHAP08_UTEST_TRANSFORM_H_

#include <vector>
#include "cppunit/extensions/HelperMacros.h"


class TransformTest : public CppUnit::TestFixture {

 private:

    std::vector<int> *v1;
    std::vector<int> *v2;
    std::vector<int> *dest_a;
    std::vector<int> *dest_b;

    
 public:

    void setUp();
    void tearDown();
    static int twice(int k);
    static int product(int r, int s);
    
    void test_equal_iters();
    void test_transform();

    CPPUNIT_TEST_SUITE(TransformTest);
    CPPUNIT_TEST(test_equal_iters);
    CPPUNIT_TEST(test_transform);
    CPPUNIT_TEST_SUITE_END();
};


#endif
