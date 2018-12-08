#include <iostream>
#include <queue>
#include <map>

#include "Caregiver.h"
#include "Citizen.h"

#ifndef ER_H_
#define ER_H_

class ER {
private:
	std::priority_queue<Citizen*> patientQueue;

	std::vector<Caregiver> caregivers;

	friend class Caregiver;

public:

};

#endif