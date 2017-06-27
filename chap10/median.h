#ifndef CHAP10_MEDIAN_H_
#define CHAP10_MEDIAN_H_

#include <algorithm>    // to get the declaration of `sort'
#include <stdexcept>    // to get the declaration of `domain_error'


template <class T, class Ran>
T median(Ran beg, Ran end) {

    int size = end - beg;
    if (size <= 0) {
    	throw std::logic_error("median of an empty vector");
    }

    // allocate memory to copy data to
    T* copy_beg = new T[size];
    T* copy_end = copy_beg + size;
    
    // copy contents of data
    for (T* copy_curr = copy_beg; copy_curr != copy_end; ) {
    	*copy_curr = *beg;
    	copy_curr++; beg++;
    }
	
    // sort copied data
    std::sort(copy_beg, copy_end);

    // find the middle element.  If there are an even number of elements then it
    // is the right-hand element of the two, since we use zero-based indexing.
    T* copy_mid = copy_beg + size / 2;
    
    // calculate median
    T median_val = (size % 2 == 0) ?
    	(*(copy_mid - 1) + *copy_mid) / 2 :
    	*copy_mid;

    // deallocate memory
    delete[] copy_beg;
    
    return median_val;
}

#endif
