// Page 186
//
// Test the class by rewriting the split function to put its output into a
// String_list.

#include <iostream>
#include "string_list.h"
#include "split.h"


int main() {

    // create a string with multiple words
    std::string stanza = "  Let     it    be   known   there  is   a   fountain  \n";
    stanza += "  That   was      not   made    by   the  hands    of   men \n";

    // use the copy constructor to create a new `StringList' object from the
    // return value from `split'.
    StringList lyrics = split(stanza);

    // print out the words, each followed by a colon
    for (StringList::const_iterator iter = lyrics.begin();  iter != lyrics.end(); iter++) {
    	std::cout << *iter << ":";
    }
    std::cout << "\n";

    return 0;
}
