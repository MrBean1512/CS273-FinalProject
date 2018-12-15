#include "Nurse.h"

Nurse::Nurse(//std::map<Citizen*, int>* record, 
	std::priority_queue<Citizen*>* patientQueue10, 
	Stats* stat)
{
	stats = stat;
	//Record = record;
	this->patientQueue1 = patientQueue10;
}

void Nurse::update(int *i)
{
	if (curPatient.size() > 0) {	//if the nurse is currently working on someone
		if (getTreatmentTime() > 1)	//if more time remains
			decrementTreatmentTime();
		else {	//they are done being treated
			//put patient back into citizens vector
			curPatient.front()->setSicknessSeverity(0);
			curPatient.front()->flag = false;
			curPatient.front()->dismissal_time = *i;
			stats->update_report(curPatient.front());
			curPatient.pop();

		}
	}
	else {	//retrieve the next patient and assign them a random treatmentTime ranging 1-20
		if (patientQueue1->size() > 0) {//search this queue (cannot access other queue)
			curPatient.push(patientQueue1->top());
			patientQueue1->pop();
		}
		else {
			//if there is no one in line, do nothing
			return;
		}
	}
}
