# test that the array stored in `actual' is a legal sentece as defined by the
# input given on page 129.  Returns `pass' if it was a legal sentence, and
# `fail' otherwise

verify_sentence() {

    pass_status=pass
    k=0

    # the first word has to be `the'
    if [[ "${actual[0]}" != the ]]; then
	pass_status=fail
    fi
    (( k++ ))

    # now we can have an indefinite amount of adjectives, so move index past them
    while [[ "${actual[k]}" = large || "${actual[k]}" = brown || "${actual[k]}" = absurd ]]; do
	(( k++ ))
    done

    # the next word has to be a noun
    if [[ "${actual[k]}" != cat && "${actual[k]}" != dog && "${actual[k]}" != table ]]; then
	pass_status=fail
    fi
    (( k++ ))

    # the next word has to be a verb
    if [[ "${actual[k]}" != jumps && "${actual[k]}" != sits ]]; then
	pass_status=fail
    fi
    (( k++ ))

    # the next three words have to be a location phrase
    if [[ ("${actual[k]}" != on || "${actual[k+1]}" != the || "${actual[k+2]}" != stairs) &&
	      ("${actual[k]}" != under || "${actual[k+1]}" != the || "${actual[k+2]}" != sky) &&
	      ("${actual[k]}" != wherever || "${actual[k+1]}" != it || "${actual[k+2]}" != wants) ]]; then

	pass_status=fail
    fi
    (( k += 3 ))
    
    # ensure that there are no extra words
    if (( k < ${#actual[@]} )); then
	pass_status=fail
    fi

    echo $pass_status
}




# generate a sentence $ntest times and randomly generate a sentence according to
# $(./$exer_loc <<< "$input"), and for each generation test whether the sentence
# is a valid sentence using ST_ASSERT_EQUAL().

verify_ntest_sentences() {

    # each iteration generates a sentence by executing the program and tests to see
    # if the sentence is valid
    for (( i = 0; i < $ntest; i++ )); do

	# get sentence and cast as an array
	actual=( $(./$exer_loc <<< "$input") )
	
	# verify if sentence is valid.  The function returns either `pass' or `fail'
	pass_status=$(verify_sentence)

	# artificially register the test as a pass or fail
	if [[ "$pass_status" = pass ]]; then
    	    ST_ASSERT_EQUAL pass pass
	else
    	    ST_ASSERT_EQUAL not pass
	fi

    done
}
