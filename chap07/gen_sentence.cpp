#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "gen_sentence.h"
#include "split.h"
#include "nrand.h"

using std::istream;
using std::vector;
using std::string;
using std::find;
using std::logic_error;




// read a grammar from a given input stream
Grammar read_grammar(istream& in) {
    
    Grammar grammar;
    string line;

    // read the input
    while (getline(in, line)) {

	// `split' the input into words
	vector<string> entry = split(line);

	if (! entry.empty()) {
	    // use the category to store the associated rule
	    grammar[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}
    }
    
    return grammar;
}




// randomly generates a sentence according to the rules defined by `grammar'
vector<string> gen_sentence(const Grammar& grammar) {
    
    vector<string> recipe, actualize;

    // initialize recipe.  Randomly chooses one of the sentence rule defined in
    // `grammar' and appends the words in the chosen rule to recipe.
    gen_aux(grammar, "<sentence>", recipe, actualize);

    // each iteration takes the last word in `recipe' and processes via a call
    // to `gen_aux'
    while (! recipe.empty()) {

	string word = recipe.back();
	recipe.pop_back();

	gen_aux(grammar, word, recipe, actualize);
    }

    return actualize;
}




// processes `word' according to `grammar'.  If `word' is a literal word
// (i.e. not a grammar rule) then simply append to `actualize'.  If `word' is a
// grammar rule, as denoted by being bracketed by < > and with definition(s)
// defined in `grammar', then randomly select one of the definitions and append
// each the words in the chosen definition to `recipe'.

void gen_aux(const Grammar& grammar,
	     const string& word,
	     vector<string>& recipe,
	     vector<string>& actualize) {

    // if the `word' is a literal word, then simply append to the actualized
    // sentence and return
    if (! bracketed(word)) {
	actualize.push_back(word);
	return;
    }

    // if we've made it here, then `word' is token for a rule according to the
    // grammar so we must process it accordingly
    
    // locate the rule that corresponds to `word'
    Grammar::const_iterator it = grammar.find(word);
    if (it == grammar.end()) {
	throw logic_error("empty rule");
    }

    // fetch the set of possible rules
    const Rule_collection& rcollection = it->second;

    // from which we select one at random
    const Rule& rule = rcollection[ nrand(rcollection.size()) ];

    // place the rule choice on the recipe stack.  The words in the rule are
    // placed in reverse order because we want the tokens at the top of the
    // stack to be the first to be processed
    for (Rule::const_iterator curr = rule.end(); curr != rule.begin(); ) {
	curr--;
	recipe.push_back(*curr);
    }
}




// returns true if `s' starts with a `<' and ends with a `>', false otherwise
bool bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}
