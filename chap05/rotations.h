struct permute_pair {
    std::string phrase;
    std::string index;
};

std::vector<permute_pair> stream_to_rotations(std::istream& input);

void rotations(const std::vector<std::string>& words, std::vector<permute_pair>& pairs);

std::string concatenate(const std::vector<std::string>& words,
			std::vector<std::string>::const_iterator begin,
			std::vector<std::string>::const_iterator end);

bool compare_permute_pairs(const permute_pair& a, const permute_pair& b);

std::string string_to_lower(const std::string& word);

std::string::size_type max_phrase_len(std::vector<permute_pair> pairs);

void write_permuted_idx(const std::vector<permute_pair>& pairs, std::ostream& output);
