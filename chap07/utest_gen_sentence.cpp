#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestCaller.h"
#include "cppunit/extensions/HelperMacros.h"
#include "gen_sentence.h"

using std::vector;
using std::string;
using std::logic_error;



class GenAuxTest : public CppUnit::TestFixture {

private:

    Grammar *grammar;
    vector<string> *recipe, *actualize, *location;
    
public:

    void setUp() {

	grammar = new Grammar;
	recipe = new vector<string>;
	actualize = new vector<string>;
	location = new vector<string>;

	location->push_back("wherever");
	location->push_back("it");
	location->push_back("wants");
	(*grammar)["<location>"].push_back(*location);

	recipe->push_back("<ending>");
	
	actualize->push_back("the");
	actualize->push_back("dog");
	actualize->push_back("sits");
    }


    void tearDown() {
	delete grammar;
	delete recipe;
	delete actualize;
    }


    // check behavior for a literal (i.e. not a bracketed rule) word
    void test_word_literal() {

	Grammar grammar_before = *grammar;
	vector<string> recipe_before = *recipe;
	vector<string> actualize_before = *actualize;
	string word_literal = "yayaya!";
	
	gen_aux(*grammar, word_literal, *recipe, *actualize);

	// these should remain unchanged
	CPPUNIT_ASSERT(*grammar == grammar_before);
	CPPUNIT_ASSERT(*recipe == recipe_before);

	// should simply append `word_literal' to `*actualize'
	CPPUNIT_ASSERT(actualize->size() == 4);
	CPPUNIT_ASSERT((*actualize)[0] == actualize_before[0]);
	CPPUNIT_ASSERT((*actualize)[1] == actualize_before[1]);
	CPPUNIT_ASSERT((*actualize)[2] == actualize_before[2]);
	CPPUNIT_ASSERT((*actualize)[3] == word_literal);
    }


    // check behavior for a rule word
    void test_word_rule() {

	Grammar grammar_before = *grammar;
	vector<string> recipe_before = *recipe;
	vector<string> actualize_before = *actualize;
	string word_rule = "<location>";
	
	gen_aux(*grammar, word_rule, *recipe, *actualize);

	// these should location vector is reverse order
	CPPUNIT_ASSERT(*grammar == grammar_before);
	CPPUNIT_ASSERT(*actualize == actualize_before);

	// should append words from (*grammar)["<location>"][0] to *recipe, in
	// reverse
	CPPUNIT_ASSERT(recipe->size() == 4);
	CPPUNIT_ASSERT((*recipe)[0] == recipe_before[0]);
	CPPUNIT_ASSERT((*recipe)[1] == (*location)[2]);
	CPPUNIT_ASSERT((*recipe)[2] == (*location)[1]);
	CPPUNIT_ASSERT((*recipe)[3] == (*location)[0]);
    }


    // check that providing a `word' not defined in `grammer' throws an
    // exception
    void test_illegal_word() {
	CPPUNIT_ASSERT_THROW(gen_aux(*grammar, "<no_rule>", *recipe, *actualize),
			     logic_error);
    }
    

    CPPUNIT_TEST_SUITE(GenAuxTest);
    CPPUNIT_TEST(test_word_literal);
    CPPUNIT_TEST(test_word_rule);
    CPPUNIT_TEST(test_illegal_word);
    CPPUNIT_TEST_SUITE_END();    
};




int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(GenAuxTest::suite());

    return runner.run() ? 0 : 1;
}
