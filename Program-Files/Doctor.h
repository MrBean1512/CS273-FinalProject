/*////////////////////////////////////////////
Subclass of Caregiver. The doctor has access to
both priority queues but has a random treatment
time between 1-20.
////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#include <vector>

#include "Citizen.h"
#include "Caregiver.h"

#ifndef DOCTOR_H_
#define DOCTOR_H_

class Doctor : public Caregiver {
private:
	std::priority_queue<Citizen*> *patientQueue1;	//pointers to the priority queues located in the ER
	std::priority_queue<Citizen*> *patientQueue2;

public:
	Doctor(std::priority_queue<Citizen*>* patientQueue20,	//constuctor of doctor
		std::priority_queue<Citizen*>* PatientQueue10, 
		Stats* rep);

	void update(int *i);	//updates how they are treating a patient with every tick that passes
	// *i is passed in so that the statistics can be properly updated when a patient is dismissed

	void setPQ1(std::priority_queue<Citizen*> pq1) {	//setter fuctions to pass the priority queue pointers into the doctor object
		this->patientQueue1 = &pq1;
	}

	void setPQ2(std::priority_queue<Citizen*> pq2) {
		this->patientQueue2 = &pq2;
	}
};

#endif