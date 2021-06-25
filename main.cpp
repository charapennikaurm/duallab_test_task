#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "service.h"

void delete_long_services(std::vector<service>& services) {
	services.erase(
		std::remove_if(services.begin(), services.end(),[](const service& s) {return s.travel_time() > 60; }),
		services.end()
	);
}

std::vector<service> read_from_file(const std::string& filename) {
	std::vector<service> services;
	std::ifstream fin(filename);
	std::string str;
	while (std::getline(fin, str)) {
		services.push_back(service(str));
	}
	return services;
}

std::vector<service> select_best(const std::vector<service>& services) {
	std::vector<service> best_services;
	for (int i = 0; i < services.size(); ++i) {
		bool is_best = true;
		for (int j = 0; j < services.size(); ++j) {
			if (j != i && services[j].is_better(services[i])) {
				is_best = false;
				break;
			}
		}
		if (is_best) {
			best_services.push_back(services[i]);
		}
	}
	return best_services;
}

void print_timetable(const std::vector<service>& services, const std::string& filename) {
	std::ofstream fout(filename);
	for (auto s : services) {
		if (s.get_company() == "Posh") { fout << s << std::endl; }
	}
	fout << std::endl;
	for (auto s : services) {
		if (s.get_company() == "Grotty") { fout << s << std::endl; }
	}
}

int main() {
	std::vector<service> services = read_from_file("input.txt");
	delete_long_services(services);
	std::vector<service> best_services = select_best(services);
	std::sort(best_services.begin(), best_services.end(),
		[](const service& s1, const service& s2) -> bool {
			return s1.get_departure_time() < s2.get_departure_time();
		});
	print_timetable(best_services, "output.txt");
	return 0;
}