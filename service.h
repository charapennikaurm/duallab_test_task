#pragma once
#include <string>
#include <sstream>
#include "time.h"

class service {
public:
	service(const std::string& s) {
		std::istringstream in(s);
		in >> company;
		std::string tmp;
		in >> tmp;
		departure_time = time(tmp);
		in >> tmp;
		arrival_time = time(tmp);
		if (arrival_time < departure_time) {
			arrival_time.hours += 24;
		}
	}

	int travel_time() const;

	bool is_better(const service& s)const;

	const std::string& get_company()const {
		return company;
	}

	const time& get_departure_time()const {
		return departure_time;
	}

	const time& get_arrival_time()const {
		return arrival_time;
	}

	friend std::ostream& operator << (std::ostream& out, const service& s);

private:
	std::string company;
	time departure_time;
	time arrival_time;
};
