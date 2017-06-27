#!/bin/bash

# program location
exer_loc="exer09_04"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

target='the student grade input was invalid'

# test grading output
actual=$(./$exer_loc)
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
