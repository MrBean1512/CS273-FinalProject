/*////////////////////////////////////////////
Citizens are the stars of the show in this program.
Their names are what make each one unique, however,
their pointer in the "population" vector is what
is used to identify them through the program.
////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <string>

#include "Record.h"

#ifndef CITIZEN_H_
#define CITIZEN_H_

class Citizen {
private:
	int sicknessSeverity;	//used to decided which priority queue they will be placed in and how they will be ordered for priority

public:
	Citizen(std::string Name);	//constructor

	bool flag;	//tells whether or not a citizen is currently sick

	std::vector<Record*> records;	//tracks infor about individual visits

	std::string name;	//for the program as a whole, this is not used, however, it is still important so that the user can identify individual objects
	int numVisits=0;	//tracks the total number of visits

	int arrival_time=0;	//placeholder value that is accessed by the stats class at the end of every visit
	int dismissal_time=0;	//placeholder value that is accessed by the stats class at the end of every visit
	int it;

	bool operator<(const Citizen &other) const {	//used ny the priority queues so that they can properly order sick patients according to the severity of their ailment
		return sicknessSeverity < other.sicknessSeverity;
	}

	int getSicknessSeverity();
	void setSicknessSeverity(int s);
	void decrementSicknessSeverity();	//this isn't used anymore; its initial purpose was so that we could make the hospital more realistic by having nurses treat/stabilize patients before doctors take them

};

#endif