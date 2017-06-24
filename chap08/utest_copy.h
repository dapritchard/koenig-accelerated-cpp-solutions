#ifndef CHAP08_UTEST_COPY_H_
#define CHAP08_UTEST_COPY_H_

#include <vector>
#include "cppunit/extensions/HelperMacros.h"


class CopyTest : public CppUnit::TestFixture {

 private:

    std::vector<char> *v1;
    std::vector<char> *v2;
    
 public:

    void setUp();
    void tearDown();

    void test_equal_iters();
    void test_copy();

    CPPUNIT_TEST_SUITE(CopyTest);
    CPPUNIT_TEST(test_equal_iters);
    CPPUNIT_TEST(test_copy);
    CPPUNIT_TEST_SUITE_END();
};


#endif
