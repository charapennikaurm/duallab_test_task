#include "service.h"

int service::travel_time() const {
		return delta_minutes(departure_time, arrival_time);
}

bool service::is_better(const service& s) const {
	if (this->departure_time == s.departure_time &&
		this->arrival_time < s.arrival_time) {
		return true;
	}
	if (this->departure_time > s.departure_time &&
		this->arrival_time == s.arrival_time) {
		return true;
	}
	if (this->departure_time > s.departure_time &&
		this->arrival_time < s.arrival_time) {
		return true;
	}
	if (this->departure_time == s.departure_time &&
		this->arrival_time == s.arrival_time &&
		this->company == "Posh" && s.company == "Grotty") {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const service& s) {
	out << s.company << " " << s.departure_time << " " << s.arrival_time;
	return out;
}