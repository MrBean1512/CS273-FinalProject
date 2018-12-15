/*////////////////////////////////////////////
The ER class's main function is to hold the
priority queues so that the caregivers may 
access it and it also holds a vector of caregivers
////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

#include "Citizen.h"
#include "Caregiver.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Stats.h"
#include "Record.h"

#ifndef ER_H_
#define ER_H_

class ER {
private:
	friend class Caregiver;	//originally for access to the priority queues

public:
	ER();	//default constructor so that town can initialize with a place to store this
	ER(int numDoctor, int numNurse);	//replacement for the default ER intially constructed in town

	std::priority_queue<Citizen*> patientQueue10;	//priority queues where patients are "put in line" and then ordered according to how sick they are
	std::priority_queue<Citizen*> patientQueue20;	//they are split into two different queues because there is no way to give nurses access to only one half of the queue

	Stats stats;	//used to track the stats of this specific ER

	std::vector<Citizen*> *population;	//pointer to the vector where all citizen pointers are stored

	std::vector<Caregiver*> caregivers;	//stores all caregiver objects in one vector because the number of caregivers is variable based on what the user inputs


	//getter and setter functions just to reduce bugs. We ran into a lot of problems without these. Putting the priority queues into private does't work either
	//we understand that making the queues public is not ideal but our runtime increases significantly otherwise
	std::priority_queue<Citizen*> getPatientQueue10(){
		return patientQueue10;
	}

	std::priority_queue<Citizen*> getPatientQueue20() {
		return patientQueue20;
	}

	void setPatientQueue10(std::priority_queue<Citizen*> temp) {
		patientQueue10 = temp;
	}

	void setPatientQueue20(std::priority_queue<Citizen*> temp) {
		patientQueue20 = temp;
	}
	
};

#endif