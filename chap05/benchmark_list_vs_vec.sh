# functions to generate random data of the form used by exercises 5-2 and 5-3
# and test the speed of the list-based version vs. the vector-based versions of
# the programs
#
# assumes the existence of the variables:
#
#     NGRADES     a positive integer
#     NAMELEN     a positive integer
#     NOBS        an array of positive integers
#     exec_arr    an array of the filenames to be benchmarked
#     desc_arr    an array of program descriptions


# ensure that executables exist
for file in "${exec_arr[@]}"; do
    if [[ ! -x "$file" ]]; then
	>&2 echo "error: executable file $file doesn't exist"
	exit 1
    fi
done



# construct helper functions ---------------------------------------------------

# generates a uniformly distributed number between 30 and 100
rnum() {
    echo $(( RANDOM % 70 + 30 ))
}




# generates a random 10-digit name
#
# This is very slow because the call to /dev/urandom generates a huge amount of
# data each time, while we need only a few bytes.  Is there a smarter way to do
# this?

rname() {
    head -c200 /dev/urandom | tr -cd 'a-z' | head -c10
}




# generates $1 observations, where each observation is a row of data with a
# 10-digit randomly chosen name and followed by $NGRADES numbers, each with
# values between 30 and 100 and delimited by spaces

gendata() {
    
    for (( i=0 ; i < $1 ; i++ )); do

	# print random name
	printf "$(rname) "

	# print random grades
	for (( j=0 ; j < NGRADES ; j++ )); do
	    printf "$(rnum) "
	done

	echo
    done
}




# begin timing -----------------------------------------------------------------

for n in "${NOBS[@]}"; do

    data=$(gendata $n)

    echo '---------------------------------'
    for i in ${!exec_arr[@]}; do
	echo "${desc_arr[i]} with $n samples"
	time { ./${exec_arr[i]} <<< "$data" > /dev/null; }
	echo
	echo
    done
    echo '---------------------------------'
    echo
    echo
done
