#ifndef CHAP08_UTEST_REMOVE_H_
#define CHAP08_UTEST_REMOVE_H_

#include <vector>
#include "cppunit/extensions/HelperMacros.h"


class RemoveTest : public CppUnit::TestFixture {

 private:

    std::vector<char> *vec;
    
 public:

    void setUp();
    void tearDown();
    static bool is_a(char c);

    void test_equal_iters();
    void test_remove_val();
    void test_remove_pred();

    CPPUNIT_TEST_SUITE(RemoveTest);
    CPPUNIT_TEST(test_equal_iters);
    CPPUNIT_TEST(test_remove_val);
    CPPUNIT_TEST(test_remove_pred);
    CPPUNIT_TEST_SUITE_END();
};


#endif
