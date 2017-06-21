#ifndef CHAP07_GEN_SENTENCE_H_
#define CHAP07_GEN_SENTENCE_H_

#include <vector>
#include <string>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;


Grammar read_grammar(std::istream& in);

std::vector<std::string> gen_sentence(const Grammar& grammar);

void gen_aux(const Grammar& g,
	     const std::string& word,
	     std::vector<std::string>& recipe,
	     std::vector<std::string>& actualize);

bool bracketed(const std::string& s);

#endif
