#include "Doctor.h"
#include "ER.h"

Doctor::Doctor(std::vector<Citizen*>* Population, std::priority_queue<Citizen*>* patientQueue20, std::priority_queue<Citizen*>* patientQueue10)
{
		population = Population;
}

void Doctor::update()
{
	if (curPatient.size() > 0) {
		if (getTreatmentTime() > 1)	//more time remains
			decrementTreatmentTime();
		else {	//they are done being treated
			//put patient back into citizens vector
			curPatient.front()->setSicknessSeverity(0);
			population->push_back(curPatient.front());
			curPatient.pop();
		}
	}
	else {	//retrieve the next patient and assign them a random treatmentTime ranging 1-20
		if (patientQueue20->size() > 0) {//search this queue first
			curPatient.push(patientQueue20->top());
			patientQueue20->pop();
			setTreatmentTime((rand() % 20)+1);

		}
		else if (patientQueue10->size() > 0) {//then try this queue
			curPatient.push(patientQueue10->top());
			patientQueue10->pop();
		}
		else {
			//if there is no one in line, do nothing
			return;
		}
	}
}
