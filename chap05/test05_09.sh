#!/bin/bash

# program location
exer_loc="exer05_09"

# process command line arguments and define testing functions
. ../testing/system_test.sh

# we've checked for `exer05_03_vector', now check for `exer05_03_list'
if [[ ! -x exer05_03_list ]]; then
    >&2 echo "error: no executable file $exer_loc exists"
    exit 1
fi




# conduct tests ----------------------------------------------------------------

input='this Is A test What will be The Result?  awesome'

target='words with only lowercase letters:
----------------------------------
this
test
will
be
awesome
----------------------------------


words with at least one uppercase letter:
-----------------------------------------
Is
A
What
The
Result?
-----------------------------------------'

# test mixed-case input
actual=$(./$exer_loc <<< "$input")
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
