#!/bin/bash

# program location
exer_loc="./exer02_01"

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------

target_koenig="Please enter your first name: 
****************
*Hello, Koenig!*
****************"

target_moo="Please enter your first name: 
*************
*Hello, Moo!*
*************"




# program outputs --------------------------------------------------------------

out_koenig="$($exer_loc <<< Koenig)"

out_moo="$($exer_loc <<< Moo)"




# compare output to target -----------------------------------------------------

echo
if [[ "$out_koenig" = "$target_koenig" ]]; then
    echo 'Test with "Koenig" as input passed'
else
    echo 'Test with "Koenig" as input failed'
    exit_status=1
fi

echo
if [[ "$out_moo" = "$target_moo" ]]; then
    echo 'Test with "Moo" as input passed'
else
    echo 'Test with "Moo" as input failed'
    exit_status=1
fi

exit $exit_status
