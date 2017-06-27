#include <vector>
#include <string>
#include <algorithm>
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/extensions/HelperMacros.h"
#include "median.h"

using std::vector;
using std::copy;
using std::equal;
using std::logic_error;




class MedianTest : public CppUnit::TestFixture {

private:

    int *one_to_ten;
    vector<int> *zero_to_onehun;

    
public:

    void setUp() {

	one_to_ten = new int[10];
	for (int i = 0; i < 10; i++) one_to_ten[i] = i + 1;

	zero_to_onehun = new vector<int>;
	for (int i = 0; i <= 100; i++) zero_to_onehun->push_back(i);
    }


    void tearDown() {
	delete one_to_ten;
	delete zero_to_onehun;
    }


    // 
    void test_invalid_iters() {

	// beg > end
	CPPUNIT_ASSERT_THROW(median<int>(one_to_ten + 5, one_to_ten), logic_error);
	// beg == end
	CPPUNIT_ASSERT_THROW(median<int>(one_to_ten, one_to_ten), logic_error);
    }


    // 
    void test_array_input() {

	// create a local copy of one_to_ten;
	int copy_one_to_ten[10];
	copy(one_to_ten, one_to_ten + 10, copy_one_to_ten);

	// call median function
	double median_val = median<double>(one_to_ten, one_to_ten + 10);

	// check that correct value is returned
	CPPUNIT_ASSERT(median_val == 5.5);
	
	// original data should remain unchanged
	CPPUNIT_ASSERT(equal(one_to_ten, one_to_ten + 10, copy_one_to_ten));
    }


    // 
    void test_vector_input() {

    	// create a local copy of zero_to_onehun;
    	vector<int> copy_zero_to_onehun = *zero_to_onehun;

    	// call median function.  Note: it is not recommended in general to
    	// return an int since the mathematical median may not be an integer
    	// value.
    	int median_val = median<int>(zero_to_onehun->begin(), zero_to_onehun->end());

    	// check that correct value is returned
    	CPPUNIT_ASSERT(median_val == 50);
	
    	// original data should remain unchanged
    	CPPUNIT_ASSERT(copy_zero_to_onehun == *zero_to_onehun);
    }
    

    CPPUNIT_TEST_SUITE(MedianTest);
    CPPUNIT_TEST(test_invalid_iters);
    CPPUNIT_TEST(test_array_input);
    CPPUNIT_TEST(test_vector_input);
    CPPUNIT_TEST_SUITE_END();    
};




int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(MedianTest::suite());

    return runner.run() ? 0 : 1;
}
