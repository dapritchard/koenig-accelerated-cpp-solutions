#include <string>
#include "string_list.h"


// dereference operator
std::string& StringList::iterator::operator*() {
	return retrieve();
}


// prefix increment
StringList::iterator& StringList::iterator::operator++() {
    curr = curr->next;
    return *this;
}


// postfix increment
StringList::iterator StringList::iterator::operator++(int) {
    iterator old = *this;
    ++(*this);
    return old;
}


// prefix decrement
StringList::iterator& StringList::iterator::operator--() {
    curr = curr->prev;
    return *this;
}


// postfix decrement
StringList::iterator StringList::iterator::operator--(int) {
    iterator old = *this;
    --(*this);
    return old;
}
