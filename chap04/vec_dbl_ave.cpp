#include <vector>
#include <stdexcept>

using std::vector;


// returns the average of the values contained in a vector of doubles
double vec_dbl_ave(vector<double> vals) {

    // ensure that vector isn't empty
    int n_vals = vals.size();
    if (n_vals == 0) {
	throw std::invalid_argument("average of 0 entries is undefined");
    }

    // calculate the sum of the values in the vector
    double sum;
    for (int i = 0; i < n_vals; i++) {
	sum += vals[i];
    }

    // the average is the sum of the values divided by the cardinality
    return sum / n_vals;
}
