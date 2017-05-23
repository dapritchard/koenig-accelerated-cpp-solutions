#!/bin/bash

# program location
exer_loc="exer04_03"

# process command line arguments
. ../testing/process_args.sh

# declare variables to store testing data
. ../testing/declare_vars.sh




# construct tests --------------------------------------------------------------

# recreate exercise using Bash syntax
. print_squares.sh
out=$(print_squares 999)

testname[arr_idx]='exercise specificiations'
input[arr_idx]=''
target[arr_idx]="$out"
((arr_idx++))




# # conduct tests ----------------------------------------------------------------

. ../testing/conduct_tests.sh
