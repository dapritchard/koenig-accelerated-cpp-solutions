// Page 138
//
// Extend the program in §4.2.3/64 to assign letter grades by ranges:
//
//     A  90-100
//     B  80-89.99...
//     C  70-79.99...
//     D  60-69.99...
//     F  < 60
//
// The output should list how many students fall into each category.

// note: the counts for each of the grade categories are stored in an
// associative container for this exercise, but in actuality there is not
// advantage to doing so and an array or vector would be better suited.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::ostream;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::map;
using std::max;

struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};


// compute the median of a `vector<double>'
// note that calling this function copies the entire argument `vector'
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}


// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}


// read homework grades from an input stream into a `vector<double>'
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}


istream& read(istream& is, Student_info& s)
{
	// read and store the student's name and midterm and final exam grades
	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework);  // read and store all the student's homework grades
	return is;
}


bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}


int main()
{
	vector<Student_info> students;
	map<char, int> grade_cat;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all the records, and find the length of the longest name
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// alphabetize the records
	sort(students.begin(), students.end(), compare);

	// initialize all grades to 0
	grade_cat['A']; grade_cat['B']; grade_cat['C']; grade_cat['D']; grade_cat['F'];

	// write the grade for each student
	cout << "Individual student grades:\n"
	     << "--------------------------\n";
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

		// write the name, padded on the right to `maxlen' `+' `1' characters
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		// compute and write the grade
		try {
			double final_grade = grade(students[i]);

			// add 1 to the count of the appropriate grade category
			if (final_grade >= 90) ++grade_cat['A'];
			else if (final_grade >= 80) ++grade_cat['B'];
			else if (final_grade >= 70) ++grade_cat['C'];
			else if (final_grade >= 60) ++grade_cat['D'];
			else ++grade_cat['F'];

			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}

		cout << "\n";
	}

	cout << "\n"
	     << "Overall grade breakdown\n"
	     << "-----------------------\n"
	     << "A:  " << grade_cat['A'] << "\n"
	     << "B:  " << grade_cat['B'] << "\n"
	     << "C:  " << grade_cat['C'] << "\n"
	     << "D:  " << grade_cat['D'] << "\n"
	     << "F:  " << grade_cat['F'] << "\n";

	return 0;
}
