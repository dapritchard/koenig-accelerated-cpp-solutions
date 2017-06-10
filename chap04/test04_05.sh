#!/bin/bash

# program location
exer_loc="exer04_05"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

prompt='Please enter a list of words followed by an EOF character:  '
header='Word counts:
------------'

# test empty input
target="$prompt$header"
actual=$(./$exer_loc <<< "")
ST_ASSERT_EQUAL "$target" "$actual"

# test a string vector with multiple duplicates
target="$prompt$header
Ritchie		3
Thompson		1
Stroustrup		2"
actual=$(./$exer_loc <<< "Ritchie Thompson Stroustrup Ritchie Stroustrup Ritchie")
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
