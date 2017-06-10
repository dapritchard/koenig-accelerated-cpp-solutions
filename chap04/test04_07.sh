#!/bin/bash

# program location
exer_loc="exer04_07"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

target='The average of 1, 2, ..., 10 is:  5.5'
actual=$(./$exer_loc)
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
