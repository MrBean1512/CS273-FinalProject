#include "Doctor.h"
#include "ER.h"

Doctor::Doctor(std::priority_queue<Citizen*>* patientQueue20, 
	std::priority_queue<Citizen*>* patientQueue10, 
	Stats* stat)
{
	stats = stat;
	this->patientQueue2 = patientQueue20;
	this->patientQueue1 = patientQueue10;
}

void Doctor::update(int *i)
{
	if (curPatient.size() > 0) {	//if the doctor already is working on someone
		if (getTreatmentTime() > 1)	//if more time remains
			decrementTreatmentTime();
		else {	//if no more time remains then they are done being treated
			curPatient.front()->flag = false;
			curPatient.front()->dismissal_time=*i;
			stats->update_report(curPatient.front());
			curPatient.front()->setSicknessSeverity(0);
			curPatient.pop();

		}
	}
	else {	//retrieve the next patient and assign them a random treatmentTime ranging 1-20
		if (patientQueue2->size() > 0) {	//search this queue first because they are higher priority and only the doctor may access them
			curPatient.push(patientQueue2->top());
			patientQueue2->pop();
			setTreatmentTime((rand() % 20)+1);

		}
		else if (patientQueue1->size() > 0) {	//then try this queue
			curPatient.push(patientQueue1->top());
			patientQueue1->pop();
		}
		else {
			//if there is no one in line, do nothing
			return;
		}
	}
}
