#ifndef CHAP08_EXTRACT_VEC_IF_H_
#define CHAP08_EXTRACT_VEC_IF_H_

#include <vector>


// modifies `vec' so that the vector only contains `T's for elements that satify
// `pred', and returns a vector with the remaining `T's.  The elements for both
// vectors remain in the same order as they were passed into the function.

template <class T>
std::vector<T> extract_vec_if(std::vector<T>& vec, bool pred(const T&)) {
    
    std::vector<T> remove;
    typename std::vector<T>::const_iterator vec_curr;
    typename std::vector<T>::const_iterator vec_end;
    typename std::vector<T>::iterator vec_keep;

    vec_curr = vec_keep = vec.begin();
    vec_end = vec.end();

    // each iteration tests to see whether the element pointed to by `vec_curr'
    // satisfied `pred'.  If the element does, that `T' is copied to the element
    // in `vec' one past the last element that did.  If the element doesn't,
    // that `T' is appended to `remove'.
    
    for ( ; vec_curr != vec_end; vec_curr++) {

	// case: element didn't satisfy `pred'.  Append `T' to `remove'.
	if (! pred(*vec_curr)) {
	    remove.push_back(*vec_curr);
	}
	// case: element satisfied `pred'.  Copy `T' to the first element of
	// `vec' that we haven't yet copied a record to.
	else {
	    // case: not necessarily the same `T'.  The test prevents
	    // unnecessary copying if we haven't yet seen a element that didn't
	    // statisfy `pred'.
	    if (vec_keep != vec_curr) {
		*vec_keep = *vec_curr;
	    }
	    // update `vec_keep' so that we know where to place the next `T'
	    vec_keep++;
	}
    }

    // change the size of the container to only contain the elements that
    // satisfied `pred', i.e the elements who's `T's were copied to the
    // beginning of the vector
    vec.resize(vec_keep - vec.begin());
    
    return remove;
}

#endif
