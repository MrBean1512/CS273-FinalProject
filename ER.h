#include <iostream>
#include <queue>

#include "Caregiver.h"
#include "Citizen.h"

#ifndef ER_H_
#define ER_H_

class ER {
private:
	std::queue<Citizen> patientQueue10;
	std::queue<Citizen> patientQueue15;
	std::queue<Citizen> patientQueue20;
	std::vector<Caregiver> Caregivers;

	friend class Caregiver;

public:

};

#endif