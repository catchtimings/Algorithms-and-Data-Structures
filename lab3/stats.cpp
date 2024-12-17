#include "stats.h"

std::ostream& operator<<(std::ostream& os, const stats& s) {
	os << "Comparison count: " << s.comparison_count << "\tCopy count: " << s.copy_count << '\n';
	return os;
}

stats& stats::operator+=(const stats& s)
{
	comparison_count += s.comparison_count;
	copy_count += s.copy_count;

	return *this;
}

stats& stats::operator=(const stats& s)
{
	if (this != &s) {
		comparison_count = s.comparison_count;
		copy_count = s.copy_count;
	}
	return *this;
}

stats& stats::operator/=(const size_t& value)
{
	comparison_count /= value;
	copy_count /= value;
	return *this;
}

stats operator+(stats left, const stats& right) {
	return left += right;
}

stats operator/(stats left, const size_t& value)
{
	return left /= value;
}
