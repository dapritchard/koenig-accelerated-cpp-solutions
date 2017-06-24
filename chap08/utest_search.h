#ifndef CHAP08_UTEST_SEARCH_H_
#define CHAP08_UTEST_SEARCH_H_

#include <vector>
#include "cppunit/extensions/HelperMacros.h"


class SearchTest : public CppUnit::TestFixture {

 private:

    std::vector<char> *v1;
    std::vector<char> *v2;
    
 public:

    void setUp();
    void tearDown();

    void test_equal_first_iters();
    void test_equal_second_iters();
    void test_exists_seq();
    void test_doesnt_exist_seq();

    CPPUNIT_TEST_SUITE(SearchTest);
    CPPUNIT_TEST(test_equal_first_iters);
    CPPUNIT_TEST(test_equal_second_iters);
    CPPUNIT_TEST(test_exists_seq);
    CPPUNIT_TEST(test_doesnt_exist_seq);
    CPPUNIT_TEST_SUITE_END();
};


#endif
