#!/bin/bash

# program location
exer_loc="./exer00_04"
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file ${exer_loc#./} exists"
    exit 1
fi

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------

# write in two lines so that the first tab can be clearly seen
target_hello="$(tail -n -6 exer00_00.cpp)"




# program outputs --------------------------------------------------------------

out_hello="$($exer_loc)"




# compare output to target -----------------------------------------------------

echo
if [[ "$out_hello" = "$target_hello" ]]; then
    echo 'Writing Hello, World! program to output passed'
else
    echo 'Writing Hello, World! program to output failed'
    exit_status=1
fi

exit $exit_status
