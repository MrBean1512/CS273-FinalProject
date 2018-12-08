#include <iostream>
#include <queue>
#include <map>
#include <vector>

#include "Caregiver.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Citizen.h"

#ifndef ER_H_
#define ER_H_

class ER {
private:
	std::priority_queue<Citizen*> patientQueue10;
	std::priority_queue<Citizen*> patientQueue20;

	std::vector<Citizen*>* population;

	std::vector<Caregiver*> caregivers;
	friend class Caregiver;

public:
	ER(std::vector<Citizen*>* population, int numDoctor, int numNurse);
};

#endif