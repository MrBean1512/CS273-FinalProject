#include <iostream>
#include <queue>
//#include <map>
#include <vector>

#include "Citizen.h"
#include "Stats.h"

#ifndef CAREGIVER_H_
#define CAREGIVER_H_

class Caregiver {
private:
	int treatmentTime = 0;
	
public:
	std::queue<Citizen*> curPatient;
	//std::map<Citizen*, int>* Record;
	Stats* stats;

	virtual void update(int *i) = 0;

	int getTreatmentTime();
	void setTreatmentTime(int t);
	void decrementTreatmentTime();
	
};

#endif