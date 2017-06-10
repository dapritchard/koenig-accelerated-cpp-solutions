#ifndef _COUNT_UNIQUE_IN_STREAM_H_
#define _COUNT_UNIQUE_IN_STREAM_H_

std::vector<std::string> stream_to_words(std::istream& input, std::ostream& output);
void n_unique(const std::vector<std::string> word_vec,
	      std::vector<std::string>& unique_vec,
	      std::vector<int>& wcount_vec);

#endif
