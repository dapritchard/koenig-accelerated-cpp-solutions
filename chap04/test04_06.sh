#!/bin/bash

# program location
exer_loc="exer04_06"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

input='john 0.9 0.8 0.9 0.6 0.7 0.8
frank 1.0 0.8 1.0 0.9 0.9
dave 0.7 0.9 0.8 0.7 0.9'

target='dave  0.82
frank 0.88
john  0.8'

actual=$(./$exer_loc <<< "$input")

ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
