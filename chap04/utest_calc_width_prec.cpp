#include <vector>
#include <string>
#include "../testing/UnitTest.h"
#include "calc_nchars.h"
#include "calc_seq.h"


class Test_calc_width_prec : public UnitTest {

public:

    void runTest() {

	std::vector<double> orig_vals, square_vals;
	std::vector<std::string> orig_chars, square_chars;
	std::vector<int> orig_after, square_after;
	int max_orig_before, max_orig_after, max_square_before, max_square_after;
	int n_rows;

	// obtain the sequence of numbers that are to be squared
	orig_vals = calc_seq(-1.0, 1.0, 0.125);
	n_rows = orig_vals.size();

	// calculate sequence of squared numbers
	for (int i = 0; i < n_rows; i++) {
	    square_vals.push_back(orig_vals[i] * orig_vals[i]);
	}

	calc_width_prec(orig_vals,
			square_vals,
			orig_chars,
			square_chars,
			orig_after,
			square_after,
			max_orig_before,
			max_orig_after,
			max_square_before,
			max_square_after);

	UT_ASSERT(orig_chars[0]  == "-1.");
	UT_ASSERT(orig_chars[1]  == "-0.875");
	UT_ASSERT(orig_chars[2]  == "-0.75");
	UT_ASSERT(orig_chars[3]  == "-0.625");
	UT_ASSERT(orig_chars[4]  == "-0.5");
	UT_ASSERT(orig_chars[5]  == "-0.375");
	UT_ASSERT(orig_chars[6]  == "-0.25");
	UT_ASSERT(orig_chars[7]  == "-0.125");
	UT_ASSERT(orig_chars[8]  ==  "0.");
	UT_ASSERT(orig_chars[9]  ==  "0.125");
	UT_ASSERT(orig_chars[10] ==  "0.25");
	UT_ASSERT(orig_chars[11] ==  "0.375");
	UT_ASSERT(orig_chars[12] ==  "0.5");
	UT_ASSERT(orig_chars[13] ==  "0.625");
	UT_ASSERT(orig_chars[14] ==  "0.75");
	UT_ASSERT(orig_chars[15] ==  "0.875");
	UT_ASSERT(orig_chars[16] ==  "1.");

	UT_ASSERT(square_chars[0]  == "1.");
	UT_ASSERT(square_chars[1]  == "0.765625");
	UT_ASSERT(square_chars[2]  == "0.5625");
	UT_ASSERT(square_chars[3]  == "0.390625");
	UT_ASSERT(square_chars[4]  == "0.25");
	UT_ASSERT(square_chars[5]  == "0.140625");
	UT_ASSERT(square_chars[6]  == "0.0625");
	UT_ASSERT(square_chars[7]  == "0.015625");
	UT_ASSERT(square_chars[8]  == "0.");
	UT_ASSERT(square_chars[9]  == "0.015625");
	UT_ASSERT(square_chars[10] == "0.0625");
	UT_ASSERT(square_chars[11] == "0.140625");
	UT_ASSERT(square_chars[12] == "0.25");
	UT_ASSERT(square_chars[13] == "0.390625");
	UT_ASSERT(square_chars[14] == "0.5625");
	UT_ASSERT(square_chars[15] == "0.765625");
	UT_ASSERT(square_chars[16] == "1.");

	UT_ASSERT(orig_after[0]  == 0);
	UT_ASSERT(orig_after[1]  == 3);
	UT_ASSERT(orig_after[2]  == 2);
	UT_ASSERT(orig_after[3]  == 3);
	UT_ASSERT(orig_after[4]  == 1);
	UT_ASSERT(orig_after[5]  == 3);
	UT_ASSERT(orig_after[6]  == 2);
	UT_ASSERT(orig_after[7]  == 3);
	UT_ASSERT(orig_after[8]  == 0);
	UT_ASSERT(orig_after[9]  == 3);
	UT_ASSERT(orig_after[10] == 2);
	UT_ASSERT(orig_after[11] == 3);
	UT_ASSERT(orig_after[12] == 1);
	UT_ASSERT(orig_after[13] == 3);
	UT_ASSERT(orig_after[14] == 2);
	UT_ASSERT(orig_after[15] == 3);
	UT_ASSERT(orig_after[16] == 0);

	UT_ASSERT(square_after[0]  == 0);
	UT_ASSERT(square_after[1]  == 6);
	UT_ASSERT(square_after[2]  == 4);
	UT_ASSERT(square_after[3]  == 6);
	UT_ASSERT(square_after[4]  == 2);
	UT_ASSERT(square_after[5]  == 6);
	UT_ASSERT(square_after[6]  == 4);
	UT_ASSERT(square_after[7]  == 6);
	UT_ASSERT(square_after[8]  == 0);
	UT_ASSERT(square_after[9]  == 6);
	UT_ASSERT(square_after[10] == 4);
	UT_ASSERT(square_after[11] == 6);
	UT_ASSERT(square_after[12] == 2);
	UT_ASSERT(square_after[13] == 6);
	UT_ASSERT(square_after[14] == 4);
	UT_ASSERT(square_after[15] == 6);
	UT_ASSERT(square_after[16] == 0);

	UT_ASSERT(max_orig_before == 2);
	UT_ASSERT(max_orig_after == 3);
	UT_ASSERT(max_square_before == 1);
	UT_ASSERT(max_square_after == 6);
    }

};


int main() {

    Test_calc_width_prec test;
    test.runTest();

    return UnitTest::getNumFail();
}
