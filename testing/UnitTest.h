#ifndef _UNIT_TEST_H_
#define _UNIT_TEST_H_


// macro definitions -----------------------------------------------------------

#include <cstdio>


// assert that boolean `condition' is true
#define UT_ASSERT(condition)  \
    assertTrue(condition, __FILE__, __LINE__, #condition)


// assert that an error of type `ExceptionType' is thrown
#define UT_ASSERT_THROW(expression, ExceptionType) {			\
									\
	try {								\
	    expression;							\
	    printf("test %d:    *** FAILURE ***     %s:%d:%s,%s\n",	\
		   num_test, __FILE__, __LINE__,			\
		   #expression,	#ExceptionType);			\
	} catch (const ExceptionType &) {				\
	    printf("test %d:    success\n", num_test);			\
	    ++num_test_success;						\
	} catch (...) {							\
	    printf("test %d:    *** FAILURE ***     %s:%d:%s,%s\n",	\
		   num_test, __FILE__, __LINE__,			\
		   #expression,	#ExceptionType);			\
	}								\
									\
	++num_test;							\
									\
    }




// class specifications --------------------------------------------------------

class UnitTest {

 public:
    
    virtual ~UnitTest() {}
    virtual void runTest() = 0;
    static int getNumSuccess() { return num_test_success; }
    static int getNumFail() { return num_test - num_test_success; }

 protected:

    void assertTrue(bool condition, const char *file,
		    int line, const char *msg);
    
    static int num_test;
    static int num_test_success;

};

#endif
