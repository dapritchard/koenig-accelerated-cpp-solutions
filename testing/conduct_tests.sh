# shell script fragment for testing framework
# conducts tests on the executable


# conduct tests ----------------------------------------------------------------

# each iteration runs one test in prints whether or not the test was successful
for i in "${!testname[@]}"; do
    echo

    # create variables for current iteration for test name, program output, and
    # target output
    curr_testname=${testname[i]}
    curr_out=$(./"$exer_loc" <<< "${input[i]}")
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
