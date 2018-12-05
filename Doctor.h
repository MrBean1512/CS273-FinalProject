#include <iostream>
#include <queue>

#include "Citizen.h"
#include "Caregiver.h"

#ifndef DOCTOR_H_
#define DOCTOR_H_

class Doctor : public Caregiver {
private:

public:
	void update();

};

#endif