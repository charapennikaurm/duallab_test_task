#pragma once
#include <string>
#include <iostream>

class time {
public:
	friend class service;

	time() :hours(), minutes() {};

	time(int hours, int minutes) :hours(hours), minutes(minutes) {};

	time(const std::string& s) {
		hours = std::stoi(s.substr(0, 2));
		minutes = std::stoi(s.substr(3, 2));
	}

	bool operator < (const time& t)const {
		return this->to_minutes() < t.to_minutes();
	}

	bool operator == (const time& t)const {
		return this->to_minutes() == t.to_minutes();
	}

	bool operator >(const time& t)const {
		return t < *this;
	}

	friend int delta_minutes(const time& t1, const time& t2);

	friend std::ostream& operator <<(std::ostream& out, const time& t);
	

private:
	int to_minutes() const {//returns time in minutes from 0:00
		return hours * 60 + minutes;
	}

private:
	int hours;
	int minutes;
};