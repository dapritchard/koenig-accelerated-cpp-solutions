#include <vector>
#include <string>
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestCaller.h"
#include <cppunit/extensions/HelperMacros.h>
#include "student_info.h"

using std::vector;
using std::string;

vector<Student_info> extract_fails(vector<Student_info>& v);
   



class ExtractFailsTest : public CppUnit::TestFixture {

private:
    
    Student_info *s0, *s1, *s2, *s3;
    vector<Student_info> *input_four;

public:

    void setUp() {

	s0 = new Student_info;
	s1 = new Student_info;
	s2 = new Student_info;
	s3 = new Student_info;
	input_four = new vector<Student_info>;

	s0->name = "bill";
	s0->midterm = 32;
	s0->final = 45;
	s0->homework.push_back(55);
	
	s1->name = "john";
	s1->midterm = 88;
	s1->final = 92;
	s1->homework.push_back(80);

	s2->name = "joe";
	s2->midterm = 45;
	s2->final = 52;
	s2->homework.push_back(20);

	s3->name = "frank";
	s3->midterm = 77;
	s3->final = 96;
	s3->homework.push_back(100);
	
	input_four->push_back(*s0);
	input_four->push_back(*s1);
	input_four->push_back(*s2);
	input_four->push_back(*s3);
    }


    void tearDown() {
	delete s0;
	delete s1;
	delete s2;
	delete s3;
	delete input_four;
    }
    

    // test for empty data case
    void test_empty() {

	vector<Student_info> empty_in;
	vector<Student_info> out;
	out = extract_fails(empty_in);
	
	CPPUNIT_ASSERT(empty_in.empty());
	CPPUNIT_ASSERT(out.empty());
    }


    // test the return vector with the failed students' `Student_info's
    void test_four_fail() {

	vector<Student_info> fail = extract_fails(*input_four);

	CPPUNIT_ASSERT(fail.size() == 2);
	
	CPPUNIT_ASSERT(fail[0].name == "bill");
	CPPUNIT_ASSERT(fail[0].midterm == 32);
	CPPUNIT_ASSERT(fail[0].final == 45);
	CPPUNIT_ASSERT(fail[0].homework.size() == 1);
	CPPUNIT_ASSERT(fail[0].homework[0] == 55);
	
	CPPUNIT_ASSERT(fail[1].name == "joe");
	CPPUNIT_ASSERT(fail[1].midterm == 45);
	CPPUNIT_ASSERT(fail[1].final == 52);
	CPPUNIT_ASSERT(fail[1].homework.size() == 1);
	CPPUNIT_ASSERT(fail[1].homework[0] == 20);
    }


    // test that the input vector is modified so as to only include the passing
    // students' `Student_info's
    void test_four_pass() {

	extract_fails(*input_four);

	CPPUNIT_ASSERT(input_four->size() == 2);
	
	CPPUNIT_ASSERT((*input_four)[0].name == "john");
	CPPUNIT_ASSERT((*input_four)[0].midterm == 88);
	CPPUNIT_ASSERT((*input_four)[0].final == 92);
	CPPUNIT_ASSERT((*input_four)[0].homework.size() == 1);
	CPPUNIT_ASSERT((*input_four)[0].homework[0] == 80);
	
	CPPUNIT_ASSERT((*input_four)[1].name == "frank");
	CPPUNIT_ASSERT((*input_four)[1].midterm == 77);
	CPPUNIT_ASSERT((*input_four)[1].final == 96);
	CPPUNIT_ASSERT((*input_four)[1].homework.size() == 1);
	CPPUNIT_ASSERT((*input_four)[1].homework[0] == 100);
    }


    CPPUNIT_TEST_SUITE(ExtractFailsTest);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST(test_four_fail);
    CPPUNIT_TEST(test_four_pass);
    CPPUNIT_TEST_SUITE_END();    
};




int main() {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(ExtractFailsTest::suite());

    return runner.run() ? 0 : 1;
}
