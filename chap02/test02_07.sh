#!/bin/bash

# program location
exer_loc="./exer02_07"

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------

target="10  9  8  7  6  5  4  3  2  1  0  -1  -2  -3  -4  -5  "




# program outputs --------------------------------------------------------------

out="$($exer_loc)"




# compare output to target -----------------------------------------------------

echo
if [[ "$target" = "$out" ]]; then
    echo 'Test passed'
else
    echo 'Test failed'
    exit_status=1
fi

exit $exit_status
