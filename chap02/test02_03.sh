#!/bin/bash

# program location
exer_loc="./exer02_03"
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file ${exer_loc#./} exists"
    exit 1
fi

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# target outputs ---------------------------------------------------------------

# 0 height and 0 width padding
target_h0_w0="Please enter your first name: Please enter a nonnegative integer for the height padding: Please enter a nonnegative integer for the width padding: 
****************
*Hello, Koenig!*
****************"

# 1 height and 4 width padding
target_h1_w4="Please enter your first name: Please enter a nonnegative integer for the height padding: Please enter a nonnegative integer for the width padding: 
************************
*                      *
*    Hello, Koenig!    *
*                      *
************************"




# program outputs --------------------------------------------------------------

# 0 height and 0 width padding
out_h0_w0="$($exer_loc <<< "Koenig
0
0")"

# 1 height and 4 width padding
out_h1_w4="$($exer_loc <<< "Koenig
1
4")"




# compare output to target -----------------------------------------------------

echo
if [[ "$out_h0_w0" = "$target_h0_w0" ]]; then
    echo 'Test with height 0 and width 0 as input passed'
else
    echo 'Test with height 0 and width 0 as input failed'
    exit_status=1
fi

echo
if [[ "$out_h1_w4" = "$target_h1_w4" ]]; then
    echo 'Test with height 1 and width 4 as input passed'
else
    echo 'Test with height 1 and width 4 as input failed'
    exit_status=1
fi

exit $exit_status
