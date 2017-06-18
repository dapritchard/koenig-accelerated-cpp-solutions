#!/bin/bash

# program location
exer_loc="exer06_02"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

input='://shouldntwork.com is bogus.  Here is one website http://www.cppreference.com
and another http://www.cplusplus.com and here is another bogus one http://'

target='http://www.cppreference.com
http://www.cplusplus.com'

# test example data
actual=$(./$exer_loc <<< "$input")
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
