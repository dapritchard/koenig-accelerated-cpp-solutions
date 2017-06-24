#ifndef CHAP08_UTEST_FIND_H_
#define CHAP08_UTEST_FIND_H_

#include <vector>
#include "cppunit/extensions/HelperMacros.h"


class FindTest : public CppUnit::TestFixture {

 private:

    std::vector<char> *vec;
    
 public:

    void setUp();
    void tearDown();
    static bool is_d(char c);
    static bool is_z(char c);
    
    void test_equal_iters();
    void test_exists();
    void test_doesnt_exist();

    CPPUNIT_TEST_SUITE(FindTest);
    CPPUNIT_TEST(test_equal_iters);
    CPPUNIT_TEST(test_exists);
    CPPUNIT_TEST(test_doesnt_exist);
    CPPUNIT_TEST_SUITE_END();
};


#endif
