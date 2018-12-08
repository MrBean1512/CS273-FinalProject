#include <iostream>
#include <queue>
#include <vector>

#include "Citizen.h"

#ifndef CAREGIVER_H_
#define CAREGIVER_H_

class Caregiver {
private:
	int treatmentTime;

public:

	virtual void update() = 0;
	std::queue<Citizen *> curPatient;	//public so that subclasses have access to it
	std::vector<Citizen*>* population;

	int getTreatmentTime();
	void setTreatmentTime(int t);
	void decrementTreatmentTime();
	

};

#endif