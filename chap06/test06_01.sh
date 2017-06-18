#!/bin/bash

# program location
exer_loc="exer06_01"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

target='this is an **************
example    * this is an *
to         * example    *
illustrate * to         *
framing    * illustrate *
           * framing    *
           **************'

# test mixed-case input
actual=$(./$exer_loc)
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
