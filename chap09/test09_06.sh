#!/bin/bash

# program location
exer_loc="exer09_06"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

input='
Emma        64   50
Sophia      56   60
Noah        60   56
Isabella    38   70
Ethen       54   85
Liam        53   57
Alexander   51   49
James       64   89
Mia         64   54
William     40   61
Michael     55   63
Olivia      60   90
Ava         46   51
Charlotte   54   86
Harper      65   56
Emily       53   71
Abigail     65   75
Mason       43   70
Benjamin    57   69
Jacob       40   60'

target='Passing students:
-----------------
Alexander
Ava
Emma
Isabella
Jacob
Liam
Mason
Mia
Michael
Noah
Sophia
William

Failing students:
-----------------
Abigail
Benjamin
Charlotte
Emily
Ethen
Harper
James
Olivia'

# test grading output
actual=$(./$exer_loc <<< "$input")
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
