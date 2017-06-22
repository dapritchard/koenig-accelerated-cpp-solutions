#!/bin/bash

# program location
exer_loc="exer07_09"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

# array used to hold sampled numbers frequency counts
table=()

# read data into a table.  See http://mywiki.wooledge.org/BashFAQ/024 for the
# redirection syntax.
while read k
do
    (( table[k]++ ))
done < <(./$exer_loc)

# these numbers taken from exer07_09.cpp
NSAMP=1000000
N=65
exp_mean=$((NSAMP / N))
range=5000
low_bnd=$((exp_mean - range))
upp_bnd=$((exp_mean + range))

# print a frequency table of the samples
echo "Frequency table of each number drawn.  The expected mean is $exp_mean"
echo ----------------------------------------------------------------------
declare -p table
echo ----------------------------------------------------------------------

# check that each frequency is within the allowed bounds
pass_status=pass
for (( k=0; k < N; k++ )); do
    if [[ ${table[k]} < $low_bnd || ${table[k]} > $upp_bnd ]]; then
	pass_status=fail
	break
    fi
done

# artificially register the test as a pass or fail
if [[ "$pass_status" = pass ]]; then
    ST_ASSERT_EQUAL pass pass
else
    ST_ASSERT_EQUAL not pass
fi


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
