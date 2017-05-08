#!/bin/bash

# program location
exer_loc="./exer03_02"
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file ${exer_loc#./} exists"
    exit 1
fi

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------

target_size_zero="Please enter a set of integers followed by an EOF character:  
You must enter your grades.  Please try again."

target_size_one="Please enter a set of integers followed by an EOF character:  The first quartile is:   99
The second quartile is:  99
The third quartile is:   99"

# data: 6 53 14 26 94 21 30 44 53 18
target_size_ten="Please enter a set of integers followed by an EOF character:  The first quartile is:   18
The second quartile is:  26
The third quartile is:   53"




# program outputs --------------------------------------------------------------

out_size_zero=$($exer_loc <<< '')

out_size_one=$($exer_loc <<< '99')

out_size_ten=$($exer_loc <<< '6 53 14 26 94 21 30 44 53 18')




# compare output to target -----------------------------------------------------

# size zero data (exit program gracefully)
echo
if [[ "$out_size_zero" = "$target_size_zero" ]]; then
    echo 'Test with data of size 0 as input passed'
else
    echo 'Test with data of size 0 as input failed'
    exit_status=1
fi

# size 1 data
echo
if [[ "$out_size_one" = "$target_size_one" ]]; then
    echo 'Test with data of size 1 as input passed'
else
    echo 'Test with data of size 1 as input failed'
    exit_status=1
fi

# size 10 data
echo
if [[ "$out_size_ten" = "$target_size_ten" ]]; then
    echo 'Test with data of size 10 as input passed'
else
    echo 'Test with data of size 10 as input failed'
    exit_status=1
fi

exit $exit_status
