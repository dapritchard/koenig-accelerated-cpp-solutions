#ifndef CHAP05_STREAM_UPP_SEG_H_
#define CHAP05_STREAM_UPP_SEG_H_

bool has_upper(const std::string& s);
std::istream& stream_upp_seg(std::istream& in,
			     std::vector<std::string>& lower,
			     std::vector<std::string>& upper);

#endif
