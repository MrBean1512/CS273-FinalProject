#include <iostream>
#include <queue>
#include <vector>

#include "Citizen.h"
#include "Caregiver.h"

#ifndef DOCTOR_H_
#define DOCTOR_H_

class Doctor : public Caregiver {
private:
	std::priority_queue<Citizen*> *patientQueue1;
	std::priority_queue<Citizen*> *patientQueue2;

public:
	Doctor(//std::map<Citizen*, int>* record, 
		std::priority_queue<Citizen*>* patientQueue20, 
		std::priority_queue<Citizen*>* PatientQueue10, 
		Stats* rep);

	void update(int *i);

	void setPQ1(std::priority_queue<Citizen*> pq1) {
		this->patientQueue1 = &pq1;
	}

	void setPQ2(std::priority_queue<Citizen*> pq2) {
		this->patientQueue2 = &pq2;
	}
};

#endif