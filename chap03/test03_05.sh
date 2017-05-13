#!/bin/bash

# program location
exer_loc="exer03_05"

# process command line arguments
. ../testing/process_args.sh

# declare variables to store testing data
. ../testing/declare_vars.sh




# construct tests --------------------------------------------------------------

continue_prompt="Do you wish to calculate another student's grade (yes / no)?  "
grade_prompt="Please enter the student's first name:  Please enter the student's midterm and final exam grades:  Enter the student's  homework grades:  "
final_output="Final grades:
-------------"

testname[arr_idx]='1 student'
input[arr_idx]='john 0.9 0.8 1.0 0.7 0.8 0.8
no'
target[arr_idx]="$grade_prompt$continue_prompt$final_output
john		0.83"
((arr_idx++))

testname[arr_idx]='2 students'
input[arr_idx]='john 0.9 0.8 1.0 0.7 0.8 0.8
yes frank 0.8 0.95 1.0 0.9 1.0 0.8
no'
target[arr_idx]="$grade_prompt$continue_prompt$grade_prompt$continue_prompt$final_output
john		0.83
frank		0.91"
((arr_idx++))

testname[arr_idx]='invalid yes/no'
input[arr_idx]='john 0.9 0.8 1.0 0.7 0.8 0.8
asdf ggg hhh yes frank 0.8 0.95 1.0 0.9 1.0 0.8
no'
target[arr_idx]="$grade_prompt$continue_prompt$continue_prompt$continue_prompt$continue_prompt$grade_prompt$continue_prompt$final_output
john		0.83
frank		0.91"
((arr_idx++))




# conduct tests ----------------------------------------------------------------

. ../testing/conduct_tests.sh
