#include <vector>
#include <stdexcept>


/* Creates a vector with a sequence of value starting at `start' and with the (k
 * + 1)-th element equal to the k-th element incremented by `by' such that the
 * largest value no larger than `end'.  So for example, calc_seq(0, 1, 0.4)
 * returns a vector with values 0.0, 0.4, and 0.8.
 */
std::vector<double> calc_seq(double start, double end, double by) {

    if (start > end) {
	throw std::invalid_argument("start > end");
    }
    else if (by <= 0) {
	throw std::invalid_argument("by <= 0");
    }

    std::vector<double> seq_vec;

    for (double curr = start; curr <= end; curr += by) {
    	seq_vec.push_back(curr);
    }
    
    return seq_vec;
}    
