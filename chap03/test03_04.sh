#!/bin/bash

# program location
exer_loc="exer03_04"

# process command line arguments
. ../testing/process_args.sh

# declare variables to store testing data
. ../testing/declare_vars.sh




# construct tests --------------------------------------------------------------

prompt='Please enter a list of words followed by an EOF character:  '
shortest='The length of the shortest string was:  '
longest='The length of the longest string was:   '
err_msg='error: no words entered as input'

testname[arr_idx]='data of size 0'
input[arr_idx]=''
target[arr_idx]="$prompt$err_msg"
((arr_idx++))

testname[arr_idx]='data of size 1'
input[arr_idx]='C++'
target[arr_idx]="$prompt${shortest}3
${longest}3"
((arr_idx++))

testname[arr_idx]='multiple words'
input[arr_idx]='The Free Software Foundation'
target[arr_idx]="$prompt${shortest}3
${longest}10"
((arr_idx++))




# conduct tests ----------------------------------------------------------------

. ../testing/conduct_tests.sh
