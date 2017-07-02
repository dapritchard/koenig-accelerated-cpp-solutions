// Note that we don't really have enough information to write this class until
// after chapter 11 because we haven't yet been introduced to the overloaded
// operators syntax.  Furthermore, much of the code in this class is based on
// the book "Data Structures and Algorithms in C++" by Mark Allen Weiss, section
// 3.5.  The source code for that implementation can be found at:
//
//     http://users.cis.fiu.edu/~weiss/dsaa_c++3/code/List.h
//
// The main thing to understand about this construction of the list class is
// that the class creates a head and a tail node which are sentinal nodes.
// These nodes mark one item before the first logical item in the list, and one
// item past the last logical item in the list.  Thus there are always two more
// nodes in the list than logical items, even when the list has zero logical
// items.  The purpose of these sentinal nodes is that they simplify the coding
// by removing a number of special cases.

#ifndef CHAP10_STRING_LIST_H_
#define CHAP10_STRING_LIST_H_

#include <string>




// StringList outer class ------------------------------------------------------

class StringList {

private:

    // the `Node' nested class provides a typical doubly-linked node, i.e. it
    // provides memory for a `string' element and pointers to the previous and
    // next node.  The class is declared later in the file.
    struct Node;
    void init();

    // the class members track the number of elements in the class, and the
    // addresses of the sentinal nodes before the first logical element in the
    // list and after the last logical element in the list
    int n_elem;
    Node *head;
    Node *tail;


public:

    // these two nested classes provide the iterator functionality for the
    // class.  These classes are declared later in the file.
    class const_iterator;
    class iterator;

    // constructors, assignment operator, and destructor
    StringList();
    StringList(const StringList& rhs);
    StringList& operator=(const StringList& rhs);
    ~StringList();

    // iterator creation
    const_iterator begin() const;
    iterator begin();
    const_iterator end() const;
    iterator end();

    // basic class methods
    int size() const;
    bool empty() const;

    // adding elements to the list
    void push_front(const std::string& x);
    iterator insert(iterator iter, const std::string& x);
    void push_back(const std::string& x);

    // removing elements from the list
    void pop_front();
    iterator erase(iterator iter);
    void pop_back();

    // remove all elements from the list
    void clear();
};




// Node nested struct ----------------------------------------------------------

struct StringList::Node {

    std::string str;
    Node *prev;
    Node *next;

    Node(const std::string& s = std::string(),
	 Node *p = 0,
	 Node *n = 0) :
	str(s), prev(p), next(n) {}
};




// const_iterator nested class -------------------------------------------------

class StringList::const_iterator {

protected:

    // `curr' corresponds to the item in the list that the iterator currently
    // points to
    Node *curr;

    // constructor used to create a new iterator.  Expects a pointer that
    // represents the current position in the list.  It is protected so as to
    // keep the constructor for internal use only.  For example, it is used by
    // `begin()' and `end()' to construct a new iterator object.
    const_iterator(Node *p) : curr(p) {}

    // internal helper function used to return the string from the item in the
    // list that the iterator points to
    std::string& retrieve() const;


public:

    // public constructor for iterator.  Must be explicitely provided because
    // the `iterator(Node *p)' constructor was written.  Otherwise the
    // zero-parameter constructor would be disabled, and hence a statement such
    // as `StringList::const_iterator iter;' would not work.
    const_iterator() : curr(0) {}

    // dereference operator.  Return the object in the list pointed to by the
    // iterator.
    const std::string& operator*();

    // increment and decrement operators.  The int parameter indicates the
    // postfix versions.  Note that the postfix versions return by value.  This
    // is because a copy must be made since we're updating the object, while
    // returning the old version.  Note that the overloaded operator syntax is
    // not introduced until section 11.2.4 pages 192-193.
    const_iterator& operator++();
    const_iterator operator++(int);
    const_iterator& operator--();
    const_iterator operator--(int);

    // comparison operators
    bool operator==(const const_iterator& rhs) const;
    bool operator!=(const const_iterator& rhs) const;

    // note: the `friend' declaration isn't introduced until section 12.3.2 page
    // 217.  It allows `StringList' to access the `StringList::const_iterator'
    // class's protected members.
    friend class StringList;
};




// iterator nested class -------------------------------------------------------

// note that inheritence isn't introduced until chapter 13


class StringList::iterator : public StringList::const_iterator {

protected:

    // internal use constructor.  Expects a pointer that represents the current
    // position in the list.
    iterator(Node *p) : const_iterator(p) {}


public:

    // zero-parameter constructor.  Relies on the parent class constructor to
    // set `curr' to 0.
    iterator() {}

    // dereference operator
    std::string& operator*();

    // increment and decrement operators
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);

    // allow `StringList' to access the `StringList::iterator' class's protected
    // members
    friend class StringList;
};


#endif
