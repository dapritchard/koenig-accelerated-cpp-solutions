/* Page 49
 *
 * Write a program that will keep track of grades for several students at once.
 * The program could keep two vectors in sync: The first should hold the
 * student's names, and the second the final grades that can be computed as
 * input is read.  For this exercise you should assume a fixed number of
 * homework grades.
 */

/* Most of the code in this program is taken from the `Computing student grades'
 * example in Section 3.1.  This program essentially puts a loop around body of
 * that program and places the results in a vectors for the student's name and
 * calculated final grade.
 */


#define NUM_HW 4

#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <string>

using std::cin;       using std::setprecision;
using std::cout;      using std::string;
using std::endl;      using std::streamsize;
using std::vector;


int main() {

    vector<string> name_vec;
    vector<double> grade_vec;
    string contin_resp;
    bool is_done;

    is_done = false;
    
    while (! is_done) {
	// ask for and read the student's name
	cout << "Please enter the student's first name:  ";
	string curr_name;
	cin >> curr_name;
	name_vec.push_back(curr_name);

	// ask for and read the midterm and final grades
	cout << "Please enter the student's midterm and final exam grades:  ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for the homework grades
	cout << "Enter the student's  homework grades:  ";

	// the number and sum of grades read so far
	double sum = 0;

	// a variable into which to read
	double x;

	// invariant:
	//     we have read `count' grades so far, and
	//     `sum' is the sum of the first `count' grades
	for (int count = 0; count < NUM_HW; count++) {
	    cin >> x;
	    sum += x;
	}

	grade_vec.push_back(0.2 * midterm + 0.4 * final + 0.4 * sum / NUM_HW);

	/* each iteration queries the user whether they want to add another
	 * student or not.  The loop ends when either `yes' or 'no' or EOF is
	 * entered.
	 */
	do {
	    
	    // ask user if there are more grades to calculate
	    cout << "Do you wish to calculate another student's grade (yes / no)?  ";
	    cin >> contin_resp;

	    // 
	    if (contin_resp == "no" || cin.eof()) {
		is_done = true;
	    }
	    
	} while (! (contin_resp == "yes" || contin_resp == "no" || cin.eof()));
    }

    // print the grade for each student entered
    cout << "Final grades:\n"
	 << "-------------\n";
    for (unsigned int i = 0; i < name_vec.size(); i++) {
	streamsize prec = cout.precision();
	cout << name_vec[i] << "\t\t" << setprecision(3) << grade_vec[i]
	     << setprecision(prec) << "\n";
    }

    return 0;
}
