#include <iostream>
#include <queue>

#include "Citizen.h"

#ifndef CAREGIVER_H_
#define CAREGIVER_H_

class Caregiver {
private:
	
public:
	std::queue<Citizen *> curPatient;
	int treatmentTime;
	virtual void update() = 0;

};

#endif
