#include <iostream>
#include <vector>
#include <string>

bool is_smallwd(const std::string& s);
std::istream& stream_ext_smallwd(std::istream& in,
				 std::vector<std::string>& small_words,
				 std::string::size_type& maxlen);
