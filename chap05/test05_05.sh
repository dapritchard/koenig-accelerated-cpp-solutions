#!/bin/bash

# program location
exer_loc="exer05_05"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

input='The quick brown fox
jumped over the fence'

target='***********
*         *
*    a    *
*   bb    *
*   ccc   *
*  dddd   *
*  eeeee  *
* ffffff  *
* ggggggg *
***********'

actual=$(./$exer_loc)

ST_ASSERT_EQUAL "$target" "$actual"


# exit code is the number of failed tests
exit $(( num_test - num_test_success ))
