#include "Doctor.h"
#include "ER.h"

Doctor::Doctor(//std::map<Citizen*, int>* record, 
	std::priority_queue<Citizen*>* patientQueue20, 
	std::priority_queue<Citizen*>* patientQueue10, 
	Stats* stat)
{
	stats = stat;
	//Record = record;
	this->patientQueue20 = patientQueue20;
	this->patientQueue10 = patientQueue10;
}

void Doctor::update(int i)
{
	if (curPatient.size() > 0) {
		if (getTreatmentTime() > 1)	//more time remains
			decrementTreatmentTime();
		else {	//they are done being treated
			curPatient.front()->flag = false;
			curPatient.front()->dismissal_time=i;
			stats->update_report(curPatient.front());
			//curPatient.front()->records.push_back(new Record(curPatient.front()->getSicknessSeverity, curPatient.front()->arrival_time, i));
			curPatient.front()->setSicknessSeverity(0);
			curPatient.pop();

		}
	}
	else {	//retrieve the next patient and assign them a random treatmentTime ranging 1-20
		if (patientQueue20->size() > 0) {//search this queue first
			curPatient.push(patientQueue20->top());
			//Record->insert ( std::pair<Citizen*, int> (patientQueue20->top(), patientQueue20->top()->getSicknessSeverity()));
			patientQueue20->pop();
			setTreatmentTime((rand() % 20)+1);

		}
		else if (patientQueue10->size() > 0) {//then try this queue
			curPatient.push(patientQueue10->top());
			//Record->insert(std::pair<Citizen*, int>(patientQueue10->top(), patientQueue10->top()->getSicknessSeverity()));
			patientQueue10->pop();
		}
		else {
			//if there is no one in line, do nothing
			return;
		}
	}
}
