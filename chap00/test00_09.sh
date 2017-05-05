#!/bin/bash

./exer00_09
exit_status=$?

if [[ $exit_status ]]; then
    echo 'The shortest possible program exited successfully'
else
    echo 'The shortest possible program did not exit successfully'
fi

exit $exit_status
