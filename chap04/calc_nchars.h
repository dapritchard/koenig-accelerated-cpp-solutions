#ifndef _CALC_NCHARS_H_
#define _CALC_NCHARS_H_

#define DEC_BUF_SIZE 2048

#include <vector>
#include <string>

int calc_nchars(int val);
void ndig_before_after(const char *char_repr, int *n_before, int *n_after);
void calc_width_prec(const std::vector<double> orig_vals,
		     const std::vector<double> square_vals,
		     std::vector<std::string>& orig_chars,
		     std::vector<std::string>& square_chars,
		     std::vector<int>& orig_after,
		     std::vector<int>& square_after,
		     int& max_orig_before,
		     int& max_orig_after,
		     int& max_square_before,
		     int& max_square_after);

#endif
