#include "time.h"

int delta_minutes(const time& t1, const time& t2) {
	return std::abs(t1.to_minutes() - t2.to_minutes());
}

std::ostream& operator<<(std::ostream& out, const time& t) {
	out << t.hours % 24 << ":";
	if (!(t.minutes / 10)) {
		out << "0";
	}
	out << t.minutes;
	return out;
}