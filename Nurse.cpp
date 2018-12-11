#include "Nurse.h"

Nurse::Nurse(//std::map<Citizen*, int>* record, 
	std::priority_queue<Citizen*>* patientQueue10, 
	Stats* stat)
{
	stats = stat;
	//Record = record;
	this->patientQueue1 = patientQueue10;
}

void Nurse::update(int i)
{
	if (curPatient.size() > 0) {
		if (getTreatmentTime() > 1)	//more time remains
			decrementTreatmentTime();
		else {	//they are done being treated
			//put patient back into citizens vector
			curPatient.front()->setSicknessSeverity(0);
			curPatient.front()->flag = false;
			curPatient.front()->dismissal_time = i;
			//curPatient.front()->records.push_back(new Record(curPatient.front()->getSicknessSeverity, curPatient.front()->arrival_time, curPatient.front()->dismissal_time));
			stats->update_report(curPatient.front());
			curPatient.pop();

		}
	}
	else {	//retrieve the next patient and assign them a random treatmentTime ranging 1-20
		if (patientQueue1->size() > 0) {//search this queue first
			curPatient.push(patientQueue1->top());
			//Record->insert(std::pair<Citizen*, int>(patientQueue10->top(), patientQueue10->top()->getSicknessSeverity()));
			patientQueue1->pop();
		}
		else {
			//if there is no one in line, do nothing
			return;
		}
	}
}
