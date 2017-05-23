
# calculate number of digits in $1.  PRE: $1 is a natural number.
calc_ndigits() {

    ndigits=0
    val=$1

    for (( ; val > 0; val /= 10 )); do
	(( ndigits++ ))
    done

    echo $ndigits
}


# print the integers between 1 and $1 and their squares in two right-aligned
# columns with 4 blanks separating the columns.  Each row contains a number and
# its square.  PRE: $1 is a natural number.
print_squares() {

    val=$1
    val_sq=$((val * val))

    col1_size=$(calc_ndigits $val)       # width of column 1 in chars
    col2_size=$(calc_ndigits $val_sq)    # width of column 2 in chars
    padding='    '

    for (( k=1; k <= val; k++ )); do

	# print right-aligned value of k
	curr_c1_size=${#k}
	for (( i = 0 ; i < col1_size - curr_c1_size ; i++ )) ; do
	    printf ' '
	done;
	printf $k

	# print padding
	printf "$padding"

	# print right-aligned value of k^2
	k_sq=$((k * k))
	curr_c2_size=${#k_sq}
	for (( i = 0 ; i < col2_size - curr_c2_size ; i++ )) ; do
	    printf ' '
	done;
	echo $k_sq
	
    done
}
