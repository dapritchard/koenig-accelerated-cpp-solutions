#include <string>
#include "string_list.h"

using std::string;




// constructors and assignment operator ----------------------------------------

// default constructor
StringList::StringList() {
    init();
}


// copy constructor.  Note that this is a deep copy since it relies on
// `operator=' which is also a deep copy.
StringList::StringList(const StringList& rhs) {
    init();
    *this = rhs;
}


// assignment operator.  Note that this is a deep copy.
StringList& StringList::operator=(const StringList& rhs) {

    // ensure that we are not self-assigning.  See section 11.3.2 pages 197-198.
    if (this == &rhs) {
	return *this;
    }

    // clear whatever data currently is stored in the object and make a deep
    // copy of the RHS.  The reason that this is a deep copy is that `push_back'
    // calls `insert', which in turn makes a brand new node using the `Node'
    // constructor.
    clear();
    for (const_iterator iter = rhs.begin(); iter != rhs.end(); iter++) {
	push_back(*iter);
    }

    return *this;
}


// destructor
StringList::~StringList() {
    clear();
    delete head;
    delete tail;
}


// helper function to create a linked list with two sentinal nodes.  The head
// and tail nodes are empty and are used to signal "one before the first item in
// the list", and "one past the last item in the list."
void StringList::init() {
    n_elem = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}




// functions to obtain iterators -----------------------------------------------

// returns a const_iterator pointing to the first logical item in the list.  If
// the list is empty then it points to the tail sentinal node.
StringList::const_iterator StringList::begin() const {
    return const_iterator(head->next);
}


// returns an iterator pointing to the first logical item in the list.  If the
// list is empty then it points to the tail sentinal node.
StringList::iterator StringList::begin() {
    return iterator(head->next);
}


// returns a const_iterator pointing to one past the last logical item in the
// list (i.e. the tail sentinal node)
StringList::const_iterator StringList::end() const {
    return const_iterator(tail);
}


// returns an iterator pointing to one past the last logical item in the list
// (i.e. the tail sentinal node)
StringList::iterator StringList::end() {
    return iterator(tail);
}




// basic list member functions -------------------------------------------------

// return the number of elements currently in the list
int StringList::size() const {
    return n_elem;
}


// return true if the list is empty, false otherwise
bool StringList::empty() const {
    return size() == 0;
}




// add items to the list -------------------------------------------------------

// insert `str' before the first item in the list
void StringList::push_front(const string& str) {
    insert(begin(), str);
}


// insert `str' before the element that `iter' is pointing to
StringList::iterator StringList::insert(StringList::iterator iter, const string& str) {

    Node *p = iter.curr;
    n_elem++;

    // create a new `Node' on the heap that points to the node before the
    // element `iter' is pointing to, and the node that `iter' is pointing to.
    // Also make the previous and next nodes point to the newly created node.
    return iterator(p->prev = p->prev->next = new Node(str, p->prev, p));
}


// insert `str' after the last item in the list
void StringList::push_back(const string& str) {
    insert(end(), str);
}




// // remove items from the list --------------------------------------------------

// remove the first item in the linked list, and free the memory being used by
// the node
void StringList::pop_front() {
    erase(begin());
}


// remove the item from the linked list that is pointed to by `iter', and free
// the memory being used by the node.  Returns an iterator pointing to the next
// item in the list.
StringList::iterator StringList::erase(StringList::iterator iter) {

    Node *p = iter.curr;
    iterator retVal(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    n_elem--;

    return retVal;
}


// remove the last item in the linked list, and free the memory being used by
// the node
void StringList::pop_back() {
    erase(--end());
}




// return the list to an empty state -------------------------------------------

// clear all of the elements in the linked list and free the memory being used
// by the nodes
void StringList::clear() {
    while(! empty()) {
	pop_front();
    }
}
