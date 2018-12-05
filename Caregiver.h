#include <iostream>
#include <queue>

#include "Citizen.h"

#ifndef CAREGIVER_H_
#define CAREGIVER_H_

class Caregiver {
private:
	Citizen *curPatient;
	int treatmentTime;

	friend class Doctor;
	friend class Nurse;

public:
	virtual void update() = 0;
	Citizen getCurPatient() { return (*curPatient); }
	int getTreatmentTime() { return (treatmentTime); }
};

#endif