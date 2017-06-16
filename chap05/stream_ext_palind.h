#include <iostream>
#include <vector>
#include <string>

bool is_palindrome(const std::string& s);

std::istream& stream_ext_palind(std::istream& in,
				std::vector<std::string>& palindromes,
				std::string::size_type& maxlen);
