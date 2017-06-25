#include "cppunit/ui/text/TestRunner.h"
#include "utest_accumulate.h"
#include "utest_copy.h"
#include "utest_equal.h"
#include "utest_find.h"
#include "utest_partition.h"
#include "utest_remove.h"
#include "utest_remove_copy.h"
#include "utest_search.h"
#include "utest_transform.h"


int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(AccumulateTest::suite());
    runner.addTest(CopyTest::suite());
    runner.addTest(EqualTest::suite());
    runner.addTest(FindTest::suite());
    runner.addTest(PartitionTest::suite());
    runner.addTest(RemoveCopyTest::suite());
    runner.addTest(RemoveTest::suite());
    runner.addTest(SearchTest::suite());
    runner.addTest(TransformTest::suite());

    return runner.run() ? 0 : 1;
}
