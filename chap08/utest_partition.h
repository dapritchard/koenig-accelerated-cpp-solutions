#ifndef CHAP08_UTEST_PARTITION_H_
#define CHAP08_UTEST_PARTITION_H_

#include <vector>
#include "cppunit/extensions/HelperMacros.h"


class PartitionTest : public CppUnit::TestFixture {

 private:

    std::vector<int> *all_neg;
    std::vector<int> *all_pos;
    std::vector<int> *mixed;

    
 public:

    void setUp();
    void tearDown();
    static bool is_neg(int k);
    
    void test_equal_iters();
    void test_all_true();
    void test_all_false();
    void test_mixed();

    CPPUNIT_TEST_SUITE(PartitionTest);
    CPPUNIT_TEST(test_equal_iters);
    CPPUNIT_TEST(test_all_true);
    CPPUNIT_TEST(test_all_false);
    CPPUNIT_TEST_SUITE_END();
};


#endif
