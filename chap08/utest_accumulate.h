#ifndef CHAP08_UTEST_ACCUMULATE_H_
#define CHAP08_UTEST_ACCUMULATE_H_

#include <vector>
#include "cppunit/extensions/HelperMacros.h"


class AccumulateTest : public CppUnit::TestFixture {

 private:

    std::vector<int> *vec;

    
 public:

    void setUp();
    void tearDown();
    
    void test_equal_iters();
    void test_accumulate();

    CPPUNIT_TEST_SUITE(AccumulateTest);
    CPPUNIT_TEST(test_equal_iters);
    CPPUNIT_TEST(test_accumulate);
    CPPUNIT_TEST_SUITE_END();
};


#endif
