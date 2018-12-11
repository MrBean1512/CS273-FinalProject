#include <iostream>
#include <queue>
//#include <map>
#include <unordered_map>
#include <vector>
#include <string>

#include "Citizen.h"
#include "Caregiver.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Stats.h"
#include "Record.h"

#ifndef ER_H_
#define ER_H_

class ER {
private:
	friend class Caregiver;

	//std::map<Citizen*, int> records;
	//std::unordered_map<std::string, std::vector<Record*>> records;
	Stats stats;

public:
	ER();
	ER(int numDoctor, int numNurse, std::vector<Citizen*>* population);

	std::vector<Citizen*> * population;

	std::priority_queue<Citizen*> patientQueue10;
	std::priority_queue<Citizen*> patientQueue20;
	std::vector<Caregiver*> caregivers;

};

#endif