#!/bin/bash

# program location
exer_loc="./exer02_08"
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file ${exer_loc#./} exists"
    exit 1
fi

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------


target="The product of the integers in the range [1, 10) is:  362880"




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
