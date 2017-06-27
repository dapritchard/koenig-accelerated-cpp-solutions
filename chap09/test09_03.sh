#!/bin/bash

# program location
exer_loc="exer09_03"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

target='the try/catch block caught an error: student has done no homework'

# test grading output
actual=$(./$exer_loc)
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
