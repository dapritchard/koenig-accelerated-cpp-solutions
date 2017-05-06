#!/bin/bash

# program location
exer_loc="./exer02_05"
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file ${exer_loc#./} exists"
    exit 1
fi

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------

target_sq2_rh2_rw2_tr2="Please enter an integer >= 2 for the square size:  **
**
Please enter an integer >= 2 for the rectangle height:  Please enter an integer >= 2 for the rectangle width:  **
**
Please enter an integer >= 2 for the triangle height:  *
* *"

target_sq3_rh4_rw8_tr5="Please enter an integer >= 2 for the square size:  ***
* *
***
Please enter an integer >= 2 for the rectangle height:  Please enter an integer >= 2 for the rectangle width:  ********
*      *
*      *
********
Please enter an integer >= 2 for the triangle height:  *
* *
*   *
*     *
* * * * *"




# program outputs --------------------------------------------------------------

out_sq2_rh2_rw2_tr2="$($exer_loc <<< "2
2
2
2")"

out_sq3_rh4_rw8_tr5="$($exer_loc <<< "3
4
8
5")"




# compare output to target -----------------------------------------------------

echo
if [[ "$out_sq2_rh2_rw2_tr2" = "$target_sq2_rh2_rw2_tr2" ]]; then
    echo 'Test with square size 2, rect. height 2 and width 2, and tri. height 2 as input passed'
else
    echo 'Test with square size 2, rect. height 2 and width 2, and tri. height 2 as input failed'
    exit_status=1
fi

echo
if [[ "$out_sq3_rh4_rw8_tr5" = "$target_sq3_rh4_rw8_tr5" ]]; then
    echo 'Test with square size 3, rect. height 4 and width 8, and tri. height 5 as input passed'
else
    echo 'Test with square size 3, rect. height 4 and width 8, and tri. height 5 as input failed'
    exit_status=1
fi

exit $exit_status
