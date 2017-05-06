#!/bin/bash

# program location
exer_loc="./exer00_03"
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file ${exer_loc#./} exists"
    exit 1
fi

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------

# write in two lines so that the first tab can be clearly seen
target_tabs='These colons are separated by a tab:	:
	<-- Leading with a tab'




# program outputs --------------------------------------------------------------

out_tabs="$($exer_loc)"




# compare output to target -----------------------------------------------------

echo
if [[ "$out_tabs" = "$target_tabs" ]]; then
    echo 'Escaping special characters test passed'
else
    echo 'Escaping special characters test failed'
    exit_status=1
fi

exit $exit_status
