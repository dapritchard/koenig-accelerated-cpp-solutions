#!/bin/bash

# program location
exer_loc="exer07_08"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

input='abcd http://www.cppreference.com efgh http://www.cppreference.com ijkl http://www.cplusplus.com
mnop http://www.cplusplus.com qrst http://www.cplusplus.com uvwx http://www.cplusplus.com yz'

target='http://www.cplusplus.com occurs on lines:                   1, 2
http://www.cppreference.com occurs on line:                 1'

# test multiple word instances input
actual=$(./$exer_loc <<< "$input")
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
