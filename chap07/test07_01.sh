#!/bin/bash

# program location
exer_loc="exer07_01"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

input="
Come hear Uncle John's Band
by the riverside
Come with me or go alone
He's come to take his children home
Come hear Uncle John's Band
playing to the tide
Come on along or go alone
he's come to take his children home"


target="seen 1 time(s)
------------------
He's
along
by
he's
me
on
playing
riverside
tide
with


seen 2 time(s)
------------------
Band
John's
Uncle
alone
children
come
go
hear
his
home
or
take
the


seen 3 time(s)
------------------
to


seen 4 time(s)
------------------
Come"

# test multiple word instances input
actual=$(./$exer_loc <<< "$input")
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
