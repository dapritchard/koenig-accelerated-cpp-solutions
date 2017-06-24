#!/bin/bash

# program location
exer_loc="exer08_04"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

target='d c b a '
actual=$(./$exer_loc)
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
