#!/bin/bash

# program location
exer_loc="exer07_04"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

# toy example data -----------------------------------------

input_small='asdf asdf jkl;
jkl; jkl; jkl;'

target_small='asdf occurs on line:                    1
jkl; occurs on lines:                   1, 2'


# multiple word instances data -----------------------------

input_multiple='C++ C++ Stroustrup        Moo C++
C++ C++ Stroustrup        Moo C++ 
C++ C++ Stroustrup 	      C++ 
C++ C++ Stroustrup 	      C++ 
C++ C++ Stroustrup Koenig Moo C++ 
C++ C++ Stroustrup Koenig Moo C++ 
C++ C++ Stroustrup Koenig     C++ 
C++ C++ Stroustrup Koenig     C++ 
C++ C++                   Moo C++ 
C++ C++                   Moo C++ 
C++ C++ 		      C++ 
C++ C++ 		      C++ 
C++ C++            Koenig Moo C++ 
C++ C++            Koenig Moo C++ 
C++ C++            Koenig     C++ 
C++ C++            Koenig     C++'

target_multiple='C++ occurs on lines:                    1, 2, 3, 4, 5, 6, 7,
                                        8, 9, 10, 11, 12, 
                                        13, 14, 15, 16
Koenig occurs on lines:                 5, 6, 7, 8, 13, 14, 
                                        15, 16
Moo occurs on lines:                    1, 2, 5, 6, 9, 10, 
                                        13, 14
Stroustrup occurs on lines:             1, 2, 3, 4, 5, 6, 7,
                                        8'


# begin tests ----------------------------------------------

# test toy example
actual=$(./$exer_loc <<< "$input_small")
ST_ASSERT_EQUAL "$target_small" "$actual"


# test multiple word instances input
actual=$(./$exer_loc <<< "$input_multiple")
ST_ASSERT_EQUAL "$target_multiple" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
