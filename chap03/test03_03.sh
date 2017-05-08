#!/bin/bash

# program location
exer_loc="./exer03_03"
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file ${exer_loc#./} exists"
    exit 1
fi

# parse command-line options
while getopts 'dhv' option; do

    case "$option" in

	d) diff_bool=true ;;

	h) echo "Options:"
	   echo "  -d    Print a diff between target and output strings"
	   echo "  -v    Print target and output strings"
	   exit 0
	   ;;

	v) verbose_bool=true ;;

	\?) exit 1 ;;
    esac
done

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# declare testing variables ----------------------------------------------------

declare -a testname
declare -a input
declare -a target

arr_idx=0




# construct tests --------------------------------------------------------------

outstring="Please enter a list of words followed by an EOF character:  Word counts:
------------"

testname[arr_idx]='data of size 0'
input[arr_idx]=''
target[arr_idx]="$outstring"
((arr_idx++))

testname[arr_idx]='data of size 1'
input[arr_idx]='C++'
target[arr_idx]="$outstring
C++		1"
((arr_idx++))

testname[arr_idx]='multiple repeating words'
input[arr_idx]='this is this is a a a test is is is'
target[arr_idx]="$outstring
this		2
is		5
a		3
test		1"
((arr_idx++))




# conduct tests ----------------------------------------------------------------

# each iteration runs one test in prints whether or not the test was successful
for i in "${!testname[@]}"; do
    echo

    # create variables for current iteration for test name, program output, and
    # target output
    curr_testname=${testname[i]}
    curr_out=$("$exer_loc" <<< "${input[i]}")
    curr_target=${target[i]}

    # test if program output matches target output
    if [[ "$curr_out" = "$curr_target" ]]; then
	echo "Test with $curr_testname passed"
    else
	echo "Test with $curr_testname failed"
	exit_status=1

	# case: verbose flag is on then print the program output 
	if [[ "$verbose_bool" = true ]]; then
	    echo ------------------------------------------------------------
	    echo '******** output ********'
	    echo "$curr_out"
	    echo '******** target ********'
	    echo "$curr_target"
	    echo ------------------------------------------------------------
	fi

	# case: diff flag is on then print a diff for target and output
	if [[ "$diff_bool" = true ]]; then
	    echo ------------------------------------------------------------
	    echo '********  diff  ********'
	    echo "$(diff <(echo "$curr_out") <(echo "$curr_target"))"
	    echo ------------------------------------------------------------
	fi

	# case: either verbose or diff info is output, add whitespace between
	# future tests for clarity
	if [[ "$verbose_bool" = true ]] || [[ "$diff_bool" = true ]]; then
	    printf "\n\n\n"
	fi
    fi
done

echo
exit $exit_status
