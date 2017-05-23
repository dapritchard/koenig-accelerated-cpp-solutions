# ensure an executable with name $exer_loc exists ------------------------------
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file $exer_loc exists"
    exit 1
fi




# declare global variables -----------------------------------------------------

# default flag values
diff_bool=false
verbose_bool=false

# tracks the number of tests and the number of successful tests
num_test=0
num_test_success=0




# parse command-line options ---------------------------------------------------

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




# integration test functions ---------------------------------------------------

# Tests program standard output against a target.  If the output of the program
# does not match the target standard output then the global variable
# $exit_status is set to 1.  The relative location of the program to be tested
# is assumed to be stored in global variable $exer_loc.  The function takes the
# following arguments:
#
#     $1:  an identifying name for the test
#     $2:  the expected standard output of the program
#     $3:  the actual standard output of the program
#
# Furthermore, if the either of the global variables $verbose_bool or $diff_bool
# are set to true then the function prints a verbose form and/or a diff of the
# program and target output.

ST_ASSERT_EQUAL_MESSAGE() {

    # create variables for test message, program output, and target output
    test_message="$1"
    test_target="$2"
    test_actual="$3"

    # test if program output matches target output
    if [[ "$test_actual" = "$test_target" ]]; then
	echo "$test_message:    success"
	(( num_test_success++ ))
    else
	echo "$test_message:    *** FAILURE ***"
	exit_status=1

	# case: verbose flag is on then print the program output 
	if [[ "$verbose_bool" = true ]]; then
	    echo ------------------------------------------------------------
	    echo '******** output ********'
	    echo "$test_actual"
	    echo '******** target ********'
	    echo "$test_target"
	    echo ------------------------------------------------------------
	fi

	# case: diff flag is on then print a diff for target and output
	if [[ "$diff_bool" = true ]]; then
	    echo ------------------------------------------------------------
	    echo '********  diff  ********'
	    echo "$(diff <(echo "$test_actual") <(echo "$test_target"))"
	    echo ------------------------------------------------------------
	fi

	# case: either verbose or diff info is output, add whitespace between
	# future tests for clarity
	if [[ "$verbose_bool" = true ]] || [[ "$diff_bool" = true ]]; then
	    printf "\n\n\n"
	fi
    fi

    (( num_test++ ))

}




ST_ASSERT_EQUAL() {
    ST_ASSERT_EQUAL_MESSAGE "test $num_test" "$1" "$2"
}


# ST_ASSERT_SUCCESS_MESSAGE() {
# }
