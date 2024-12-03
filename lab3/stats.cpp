#include "stats.h"

std::ostream& operator<<(std::ostream& os, const stats& s) {
	os << "Comparison count: " << s.comparison_count << "\tCopy count: " << s.copy_count << '\n';
	return os;
}

stats& stats::operator+(const stats& s)
{
	stats buf;
	buf.comparison_count += s.comparison_count;
	buf.copy_count += s.copy_count;

	return buf;
}

stats& stats::operator=(const stats& s)
{
	if (this != &s) {
		comparison_count = s.comparison_count;
		copy_count = s.copy_count;
	}
	return *this;
}
