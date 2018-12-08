#include <iostream>
#include <vector>
#include <string>

#include "Record.h"

#ifndef CITIZEN_H_
#define CITIZEN_H_

class Citizen {
private:
	std::string name;
	std::vector<Record> records;
	int sicknessSeverity;
public:
	Citizen(std::string Name);
	bool operator<(const Citizen &other) const {
		return sicknessSeverity < other.sicknessSeverity;
	}

	int getSicknessSeverity();
	void setSicknessSeverity(int s);
	void decrementSicknessSeverity();

};

#endif