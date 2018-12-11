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


public:
	ER();
	ER(int numDoctor, int numNurse);

	std::priority_queue<Citizen*> patientQueue10;
	std::priority_queue<Citizen*> patientQueue20;

	Stats stats;

	std::vector<Citizen*> *population;


	std::vector<Caregiver*> caregivers;

	std::priority_queue<Citizen*> getPatientQueue10(){
		return patientQueue10;
	}

	std::priority_queue<Citizen*> getPatientQueue20() {
		return patientQueue20;
	}

	void setPatientQueue10(std::priority_queue<Citizen*> temp) {
		patientQueue10 = temp;
	}

	void setPatientQueue20(std::priority_queue<Citizen*> temp) {
		patientQueue20 = temp;
	}
	
};

#endif