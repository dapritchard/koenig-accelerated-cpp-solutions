#!/bin/bash

# program location
exer_loc="exer05_03_vector"

# process command line arguments and define testing functions
. ../testing/system_test.sh

# we've checked for `exer05_03_vector', now check for `exer05_03_list'
if [[ ! -x exer05_03_list ]]; then
    >&2 echo "error: no executable file $exer_loc exists"
    exit 1
fi





# conduct tests ----------------------------------------------------------------

input='zbphgxjawq 97 76 58 61 71 43 66 31 81 99 
exoyjypozc 82 63 39 61 68 81 59 43 57 36 
rfpgufelmm 57 50 49 96 48 64 67 56 61 89 
msrwavloyl 72 91 46 92 90 90 43 54 80 85 
kjcmqcufqa 44 49 47 83 41 34 30 79 41 88 
znzoocekvf 31 53 33 81 48 49 80 99 94 85 
smaektktkz 74 76 44 87 65 91 50 88 67 65 
pxekxykmpt 60 87 92 38 95 43 32 94 37 83 
gqkrphooke 58 32 64 61 89 88 62 65 85 67 
mwgetgtlqw 92 93 87 31 83 55 99 36 74 99'

target='gqkrphooke 50.8
kjcmqcufqa 46
rfpgufelmm 56.4
znzoocekvf 59.6'

# test vector-based version
actual=$(./exer05_03_vector <<< "$input")
ST_ASSERT_EQUAL "$target" "$actual"

# test list-based version
actual=$(./exer05_03_list <<< "$input")
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
