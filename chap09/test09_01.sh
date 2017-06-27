#!/bin/bash

# program location
exer_loc="exer09_01"

# process command line arguments and define testing functions
. ../testing/system_test.sh




# conduct tests ----------------------------------------------------------------

# this data was reused from some of the exercises in chapter 6

input='
Emma        84   60   77    0   70   76    0
Sophia      76   70    0    0   75   79   84
Noah        80   66   75    0    0   72   78
Isabella    58   80    0   67   72    0   64
Ethen       74   95   89   81   96   93   80
Liam        73   67   63    0   71   69    0
Alexander   71   59   95   76   66   89   84
James       84   99   81   86   72  100   69
Mia         84   64   84   97   97   89  100
William     60   71    0    0   76   65   76
Michael     75   73   77   90   80   88   83
Olivia      80  100    0   71    0   75   76
Ava         66   61    0    0   78   75   75
Charlotte   74   96   89   82   78   87   68
Harper      85   66   85  100   90   78   80
Emily       73   81   92   72   79   66   88
Abigail     85   85   88   96   85   73   99
Mason       63   80   64   75   79    0    0
Benjamin    77   79   90   86   77   93   77
Jacob       60   70    0   78   55   51    0'

target='Abigail   86.2
Alexander 71.4
Ava       67.6
Benjamin  81.4
Charlotte 86
Emily     78.6
Emma      68.8
Ethen     88.4
Harper    77.4
Isabella  69.2
Jacob     60.4
James     88.8
Liam      66.6
Mason     70.2
Mia       81.2
Michael   77.4
Noah      71.2
Olivia    84.4
Sophia    73.2
William   66.4'

# test grading output
actual=$(./$exer_loc <<< "$input")
ST_ASSERT_EQUAL "$target" "$actual"


# exit number is number of failed tests
exit $(( num_test - num_test_success ))
