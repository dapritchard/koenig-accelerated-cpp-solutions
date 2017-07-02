#!/bin/bash

# program location
exer_loc="exer10_06"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

# this data was reused from some of the exercises in chapter 6

target='Let:it:be:known:there:is:a:fountain:That:was:not:made:by:the:hands:of:men:'

# test grading output
actual=$(./$exer_loc)
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
