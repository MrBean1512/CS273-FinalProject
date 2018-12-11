#include <iostream>
#include <queue>
#include <vector>

#include "Citizen.h"
#include "Caregiver.h"

#ifndef DOCTOR_H_
#define DOCTOR_H_

class Doctor : public Caregiver {
private:
	std::priority_queue<Citizen*> *patientQueue10;
	std::priority_queue<Citizen*> *patientQueue20;

public:
	Doctor(//std::map<Citizen*, int>* record, 
		std::priority_queue<Citizen*>* patientQueue20, 
		std::priority_queue<Citizen*>* patientQueue10, 
		Stats* rep);

	void update(int i);
};

#endif