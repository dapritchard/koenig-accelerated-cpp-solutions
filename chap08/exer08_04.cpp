// Page 154
//
// Implement the swap function that we used in section 8.2.5 page 148.

#include <iostream>
#include <vector>


template <class T> void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}


template <class Bi> void reverse(Bi begin, Bi end)
{
    while (begin != end) {
	--end;
	if (begin != end)
	    swap(*begin++, *end);
    }
}


using std::cout;
using std::vector;


int main() {

    vector<char> vec;
   
    vec.push_back('a'); vec.push_back('b'); vec.push_back('c'); vec.push_back('d');
    reverse(vec.begin(), vec.end());

    for (vector<char>::const_iterator curr = vec.begin(); curr != vec.end(); curr++) {
	cout << *curr << " ";
    }
    cout << "\n";

    return 0;
}
