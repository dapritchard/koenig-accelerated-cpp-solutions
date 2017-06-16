#!/bin/bash

# program location
exer_loc="exer05_11"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

input='a rose by any other name would smell as sweet'

target='words without either ascenders or descenders:
----------------------------------
a
rose
name
as
----------------------------------
maximum word length:  4'

# test vector-based version
actual=$(./$exer_loc <<< "$input")
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
