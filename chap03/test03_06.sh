#!/bin/bash

# program location
exer_loc="exer03_06"

# process command line arguments
. ../testing/process_args.sh

# declare variables to store testing data
. ../testing/declare_vars.sh




# construct tests --------------------------------------------------------------

name_prompt='Please enter your first name: '
grades_prompt='Please enter your midterm and final exam grades: Enter all your homework grades, followed by end-of-file: '

testname[arr_idx]='0 hw grades entered'
input[arr_idx]='John 0.9 0.8'
target[arr_idx]="${name_prompt}Hello, John!
${grades_prompt}Your final grade is 0.5"
((arr_idx++))

testname[arr_idx]='4 hw grades entered'
input[arr_idx]='John 0.9 0.8 1.0 0.7 0.8 0.8'
target[arr_idx]="${name_prompt}Hello, John!
${grades_prompt}Your final grade is 0.83"
((arr_idx++))




# conduct tests ----------------------------------------------------------------

. ../testing/conduct_tests.sh
