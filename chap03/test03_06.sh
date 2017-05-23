#!/bin/bash

# program location
exer_loc="exer03_06"
test_dir="../testing"

if [[ -r "$test_dir"/system_test.sh ]]; then
    . "$test_dir"/system_test.sh
else
    >&2 echo "error: can't find the file system_test.sh"
    exit 1
fi




# conduct tests ----------------------------------------------------------------

name_prompt='Please enter your first name: '
grades_prompt='Please enter your midterm and final exam grades: Enter all your homework grades, followed by end-of-file: '

testname='Test with 0 hw grades entered'
actual=$(./$exer_loc <<< 'John 0.9 0.8')
target="${name_prompt}Hello, John!
${grades_prompt}Your final grade is 0.5"
ST_ASSERT_EQUAL_MESSAGE "$testname" "$actual" "$target"

testname='Test with 4 hw grades entered'
actual=$(./$exer_loc <<< 'John 0.9 0.8 1.0 0.7 0.8 0.8')
target="${name_prompt}Hello, John!
${grades_prompt}Your final grade is 0.83"
ST_ASSERT_EQUAL_MESSAGE "$testname" "$actual" "$target"

exit $(( num_test - num_test_success ))
