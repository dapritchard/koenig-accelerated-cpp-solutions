#!/bin/bash

# program location
exer_loc="./exer02_09"

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------

target_less="Please enter an integer value:  Please enter another integer value:  3 is less than 4"

target_equal="Please enter an integer value:  Please enter another integer value:  3 is equal to 3"

target_more="Please enter an integer value:  Please enter another integer value:  3 is greater than 2"




# program outputs --------------------------------------------------------------

out_less="$($exer_loc <<< "3
4")"

out_equal="$($exer_loc <<< "3
3")"

out_more="$($exer_loc <<< "3
2")"




# compare output to target -----------------------------------------------------

echo
if [[ "$target_less" = "$out_less" ]]; then
    echo 'Test for first number less than second number passed'
else
    echo 'Test for first number less than second number failed'
    exit_status=1
fi

echo
if [[ "$target_equal" = "$out_equal" ]]; then
    echo 'Test for first number equal to second number passed'
else
    echo 'Test for first number equal to second number failed'
    exit_status=1
fi

echo
if [[ "$target_more" = "$out_more" ]]; then
    echo 'Test for first number more than second number passed'
else
    echo 'Test for first number more than second number failed'
    exit_status=1
fi

exit $exit_status
