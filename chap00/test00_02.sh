#!/bin/bash

# program location
exer_loc="./exer00_02"
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file ${exer_loc#./} exists"
    exit 1
fi

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------

target_escape_chars='This (") is a quote, and this (\) is a backslash.'




# program outputs --------------------------------------------------------------

out_escape_chars="$($exer_loc)"




# compare output to target -----------------------------------------------------

echo
if [[ "$out_escape_chars" = "$target_escape_chars" ]]; then
    echo 'Escaping special characters test passed'
else
    echo 'Escaping special characters test failed'
    exit_status=1
fi

exit $exit_status
