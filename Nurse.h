#include <iostream>

#include "Caregiver.h"

#ifndef NURSE_H_
#define NURSE_H_

class Nurse : public Caregiver {
private:
	std::priority_queue<Citizen*> *patientQueue1;

public:
	Nurse(//std::map<Citizen*, int>* record, 
		std::priority_queue<Citizen*>* patientQueue10, 
		Stats* stat);

	void update(int *i);
};

#endif