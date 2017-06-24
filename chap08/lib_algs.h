// Implement the following library algorithms, which we used in Chapter 6 and
// described in section 6.5 page 121.  Specify what kinds of iterators they
// require.  Try to minimize the number of distinct iterator operations that
// each function requires.


template <class In1, class In2>
bool my_equal(In1 beg1, In1 end1, In2 beg2) {

    while (beg1 != end1) {
	if (*beg1++ != *beg2++) {
	    return false;
	}
    }

    return true;
}




template <class In1, class In2>
In1 my_search(In1 beg1, In1 end1, In2 beg2, In2 end2) {

    // by definition empty search string matches the first occurance
    if (beg2 == end2) return beg1;

    for ( ; beg1 != end1; beg1++) {
	
	In1 curr1 = beg1;
	In2 curr2 = beg2;

	while (curr1 != end1 && curr2 != end2) {
	    if (*curr1 != *curr2) {
		break;
	    }
	    curr1++; curr2++;
	}

	if (curr2 == end2) return beg1;
    }

    return end1;
}




template <class In, class T>
In my_find(In beg, In end, T val) {

    for ( ; beg != end; beg++) {
	if (*beg == val) {
	    break;
	}
    }

    return beg;
}




template <class In, class Pred>
In my_find_if(In beg, In end, Pred pred) {
    
    for ( ; beg != end; beg++) {
	if (pred(*beg)) {
	    break;
	}
    }

    return beg;
}




template <class In, class Out>
Out my_copy(In beg, In end, Out dest) {

    for ( ; beg != end; beg++) {
	*dest++ = *beg;
    }

    return dest;
}





template <class In, class Out, class T>
Out my_remove_copy(In beg, In end, Out dest, T val) {

    for ( ; beg != end; beg++) {
	if (*beg != val) {
	    *dest++ = *beg;
	}
    }

    return dest;
}




template <class In, class Out, class Pred>
Out my_remove_copy_if(In beg, In end, Out dest, Pred pred) {

    for ( ; beg != end; beg++) {
	if (! pred(*beg)) {
	    *dest++ = *beg;
	}
    }

    return dest;
}




template <class For, class T>
For my_remove(For beg, For end, T val) {

    For curr = beg;

    for ( ; beg != end; beg++) {
	if (*beg != val) {
	    *curr++ = *beg;
	}
    }

    return curr;
}




template <class For, class Pred>
For my_remove_if(For beg, For end, Pred pred) {

    For curr = beg;

    for ( ; beg != end; beg++) {
	if (pred(*beg)) {
	    *curr++ = *beg;
	}
    }

    return curr;
}
