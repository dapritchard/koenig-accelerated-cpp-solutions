#!/bin/bash

# program location
exer_loc="exer06_09"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

target='to thine own self be true'

# test if the program can correctly concatenate the Shakespeare phrase hardcoded
# into `main()'
actual=$(./$exer_loc)
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
