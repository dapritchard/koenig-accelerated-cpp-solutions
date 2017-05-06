#!/bin/bash

# ensure executable file exists
if [[ ! -x exer00_09 ]]; then
    >&2 echo "error: no executable file exer00_09 exists"
    exit 1
fi

# run program to obtain exit status
./exer00_09
exit_status=$?

# ensure program exited with exit status 0
if [[ $exit_status ]]; then
    echo 'The shortest possible program exited successfully'
else
    echo 'The shortest possible program did not exit successfully'
fi

exit $exit_status
