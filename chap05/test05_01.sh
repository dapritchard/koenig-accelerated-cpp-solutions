#!/bin/bash

# program location
exer_loc="exer05_01"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

input='The quick brown fox
jumped over the fence'

target='      The quick    brown fox
jumped over the    fence
The quick brown    fox
                   jumped over the fence
         jumped    over the fence
            The    quick brown fox
    jumped over    the fence
                   The quick brown fox'

actual=$(./$exer_loc <<< "$input")

ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
