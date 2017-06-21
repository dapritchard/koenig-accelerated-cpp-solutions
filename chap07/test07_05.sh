#!/bin/bash

# program location
exer_loc="exer07_05"

# process command line arguments and define testing functions
. ../testing/system_test.sh

# source function to test for a valid sentence
. verify_sentence.sh




# conduct tests ----------------------------------------------------------------

input=$(cat grammar_input.txt)

# the number of tests to perform
ntest=10
verify_ntest_sentences


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
