/*////////////////////////////////////////////
The Caregiver class is the super class of Doctor
and Nurse.
////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#include <vector>

#include "Citizen.h"
#include "Stats.h"

#ifndef CAREGIVER_H_
#define CAREGIVER_H_

class Caregiver {
private:
	int treatmentTime = 0;	//used as a countdown to dismiss patients after they are cared for
	
public:
	std::queue<Citizen*> curPatient;	//only holds one patient at a time which is the one that is currently being treated
	//this doesn't have to be a queue but by making it one we can more easily handle errors that make their way in

	Stats* stats;	//points to the stats class so that they can update it as patients are dealt with

	virtual void update(int *i) = 0;	//this is the pure virtual function for its subclasses
	//it is updated every time a tick passes

	int getTreatmentTime();
	void setTreatmentTime(int t);
	void decrementTreatmentTime();	//this is quicker in the long run than getting and then setting the amount
	
};

#endif