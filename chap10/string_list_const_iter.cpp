#include <string>
#include "string_list.h"


// return the string from the item in the list that the iterator points to
std::string& StringList::const_iterator::retrieve() const {
    return curr->str;
}


// dereference operator
const std::string& StringList::const_iterator::operator*() {
    return retrieve();
}


// prefix increment
StringList::const_iterator& StringList::const_iterator::operator++() {
    curr = curr->next;
    return *this;
}


// postfix increment
StringList::const_iterator StringList::const_iterator::operator++(int) {
    const_iterator old = *this;
    ++(*this);
    return old;
}


// prefix decrement
StringList::const_iterator& StringList::const_iterator::operator--() {
    curr = curr->prev;
    return *this;
}


// postfix decrement
StringList::const_iterator StringList::const_iterator::operator--(int) {
    const_iterator old = *this;
    --(*this);
    return old;
}


// comparison operator
bool StringList::const_iterator::operator==(const StringList::const_iterator& rhs) const {
    return curr == rhs.curr;
}


// not equals operator
bool StringList::const_iterator::operator!=(const StringList::const_iterator& rhs) const {
    return !(curr == rhs.curr);
}
