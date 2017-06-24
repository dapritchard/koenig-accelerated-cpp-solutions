#ifndef CHAP08_UTEST_EQUAL_H_
#define CHAP08_UTEST_EQUAL_H_

#include <vector>
#include "cppunit/extensions/HelperMacros.h"


class EqualTest : public CppUnit::TestFixture {

 private:

    std::vector<int> *v1;
    std::vector<int> *v2;
    
 public:

    void setUp();
    void tearDown();

    void test_equal_iters();
    void test_equal_vecs();
    void test_not_equal_vecs();

    CPPUNIT_TEST_SUITE(EqualTest);
    CPPUNIT_TEST(test_equal_iters);
    CPPUNIT_TEST(test_equal_vecs);
    CPPUNIT_TEST(test_not_equal_vecs);
    CPPUNIT_TEST_SUITE_END();
};


#endif
