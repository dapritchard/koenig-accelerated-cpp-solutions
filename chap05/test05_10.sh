#!/bin/bash

# program location
exer_loc="exer05_10"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

input='gurgle stats Racecar paste blue RADAR wow test'

target='palindromes:
----------------------------------
stats
Racecar
RADAR
wow
----------------------------------
maximum word length:  7'

# test vector-based version
actual=$(./$exer_loc <<< "$input")
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
