/*////////////////////////////////////////////
Subclass of Caregiver. The nurse only has access to 
priorityQueue10 and has a random treatment
time between 1-10.
////////////////////////////////////////////*/
#include <iostream>

#include "Caregiver.h"

#ifndef NURSE_H_
#define NURSE_H_

class Nurse : public Caregiver {
private:
	std::priority_queue<Citizen*> *patientQueue1;	//pointers to the priority queues located in the ER

public:
	Nurse(std::priority_queue<Citizen*>* patientQueue10, 
		Stats* stat);

	void update(int *i);	//updates how they are treating a patient with every tick that passes
		// *i is passed in so that the statistics can be properly updated when a patient is dismissed
};

#endif