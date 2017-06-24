#ifndef CHAP08_UTEST_REMOVE_COPY_H_
#define CHAP08_UTEST_REMOVE_COPY_H_

#include <vector>
#include "cppunit/extensions/HelperMacros.h"


class RemoveCopyTest : public CppUnit::TestFixture {

 private:

    std::vector<char> *v1;
    std::vector<char> *v2;
    
 public:

    void setUp();
    void tearDown();
    static bool is_a(char c);
    
    void test_equal_iters();
    void test_copy_val();
    void test_copy_pred();

    CPPUNIT_TEST_SUITE(RemoveCopyTest);
    CPPUNIT_TEST(test_equal_iters);
    CPPUNIT_TEST(test_copy_val);
    CPPUNIT_TEST(test_copy_pred);
    CPPUNIT_TEST_SUITE_END();
};


#endif
