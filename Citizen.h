#include <iostream>
#include <vector>
#include <string>

#include "Record.h"

#ifndef CITIZEN_H_
#define CITIZEN_H_

class Citizen {
private:
	std::string name;
	int numVisits;
	int sicknessSeverity;
	std::vector<Record> records;
public:
	Citizen(std::string Name);
	int getNumVisits();
	bool operator<(const Citizen &other) const {
		return sicknessSeverity < other.sicknessSeverity;
	}
};

#endif