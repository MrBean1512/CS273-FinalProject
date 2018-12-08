#include <iostream>

#include "Caregiver.h"

#ifndef NURSE_H_
#define NURSE_H_

class Nurse : public Caregiver {
private:
	std::priority_queue<Citizen*> *patientQueue10;
public:
	Nurse(std::vector<Citizen*>* Population, std::priority_queue<Citizen*>* patientQueue10);

	void update();
};

#endif