// Page 154
//
// Reimplement the gen_sentence function from Chapter 7 to use output iterators
// rather than writing their output directly to a vector<string>. Test this new
// version by writing a program that attaches the output iterator directly to
// the standard output.

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <ctime>
#include <iterator>
#include "split.h"

using std::istream;           using std::cin;
using std::copy;              using std::cout;
using std::endl;              using std::find;
using std::getline;           using std::logic_error;
using std::map;               using std::string;
using std::vector;            using std::domain_error;
using std::rand;              using std::ostream_iterator;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// function declarations
Grammar read_grammar(istream& in);
template <class Out> Out gen_sentence(const Grammar& g, Out& dest);
template <class Out> void gen_aux(const Grammar& g, const string& word, Out& dest);
int nrand(int n);
bool bracketed(const string& s);




// begin main ------------------------------------------------------------------

int main() {

    ostream_iterator<string> out(cout, " ");
    gen_sentence(read_grammar(cin), out);
    cout << "\n";

    return 0;
}




// begin supporting functions --------------------------------------------------

// read a grammar from a given input stream
Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    // read the input
    while (getline(in, line)) {

	// `split' the input into words
	vector<string> entry = split(line);

	if (!entry.empty()) {
	    // use the category to store the associated rule
	    ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}
    }
    
    return ret;
}




// seed workhorse function `gen_aux' with `<sentence>' rule
template <class Out>
Out gen_sentence(const Grammar& g, Out& dest) {
    gen_aux(g, "<sentence>", dest);
    return dest;
}




// if `word' is a literal word, then store in and increment `dest'.  Otherwise
// randomly select and expand the rule and recursively process all of the words
// that the rule provides.

template <class Out>
void gen_aux(const Grammar& g, const string& word, Out& dest) {

    if (!bracketed(word)) {
	*dest++ = word;
    }
    else {
	// locate the rule that corresponds to `word'
	Grammar::const_iterator it = g.find(word);
	if (it == g.end()) {
	    throw logic_error("empty rule");
	}

	// fetch the set of possible rules
	const Rule_collection& c = it->second;

	// from which we select one at random
	const Rule& r = c[nrand(c.size())];

	// recursively expand the selected rule
	for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) {
	    gen_aux(g, *i, dest);
	}
    }
}




// int main() {
    
//     // generate the sentence
//     list<string> sentence = gen_sentence(read_grammar(cin));

//     // write the first word, if any
//     list<string>::const_iterator it = sentence.begin();
//     if (!sentence.empty()) {
// 	cout << *it;
// 	++it;
//     }

//     // write the rest of the words, each preceded by a space
//     while (it != sentence.end()) {
// 	cout << " " << *it;
// 	++it;
//     }

//     cout << endl;
//     return 0;
// }




// return a random integer in the range `[0,' `n)'
int nrand(int n) {
    
    if (n <= 0 || n > RAND_MAX) {
	throw domain_error("Argument to nrand is out of range");
    }

    const int bucket_size = RAND_MAX / n;
    int r;
    timespec seed;

    do {
	clock_gettime(CLOCK_MONOTONIC, &seed);
	srand(seed.tv_nsec);
	r = rand() / bucket_size;
    } while (r >= n);

    return r;
}




bool bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

