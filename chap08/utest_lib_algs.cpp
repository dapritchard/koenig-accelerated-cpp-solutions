#include "cppunit/ui/text/TestRunner.h"
#include "utest_copy.h"
#include "utest_equal.h"
#include "utest_find.h"
#include "utest_remove.h"
#include "utest_remove_copy.h"
#include "utest_search.h"


int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(EqualTest::suite());
    runner.addTest(SearchTest::suite());
    runner.addTest(FindTest::suite());
    runner.addTest(CopyTest::suite());
    runner.addTest(RemoveCopyTest::suite());
    runner.addTest(RemoveTest::suite());

    return runner.run() ? 0 : 1;
}
