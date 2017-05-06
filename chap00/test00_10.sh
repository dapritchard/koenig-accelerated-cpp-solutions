#!/bin/bash

# program location
exer_loc="./exer00_10"
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file ${exer_loc#./} exists"
    exit 1
fi

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------

target_hello="Hello, world!"




# program outputs --------------------------------------------------------------

out_hello="$($exer_loc)"




# compare output to target -----------------------------------------------------

echo
if [[ "$out_hello" = "$target_hello" ]]; then
    echo 'Hello, World! test passed'
else
    echo 'Hello, World! test failed'
    exit_status=1
fi

exit $exit_status
