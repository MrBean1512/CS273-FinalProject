#include <iostream>
#include <vector>
#include <string>

#include "Record.h"

#ifndef CITIZEN_H_
#define CITIZEN_H_

class Citizen {
private:
	int sicknessSeverity;

public:
	Citizen(std::string Name);

	bool flag;	//tells whether or not a citizen is currently sick

	std::vector<Record*> records;

	std::string name;
	int numVisits=0;
	int arrival_time=0;
	int dismissal_time=0;

	bool operator<(const Citizen &other) const 
	{	//for the priority queues
		return sicknessSeverity < other.sicknessSeverity;
	}

	int getSicknessSeverity();
	void setSicknessSeverity(int s);
	void decrementSicknessSeverity();

};

#endif
