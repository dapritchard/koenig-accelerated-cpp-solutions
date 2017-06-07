#!/bin/bash

# program location
exer_loc="exer04_02"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

# recreate exercise using Bash syntax
. print_squares.sh
target=$(print_squares 100)
actual=$(./$exer_loc)

ST_ASSERT_EQUAL "$target" "$actual"
