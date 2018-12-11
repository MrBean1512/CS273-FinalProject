#include "ER.h"

ER::ER()
{
	
}

ER::ER(int numDoctor, int numNurse, std::vector<Citizen*> *Population)
{
	this->population = Population;

	for (int i = 0; i < numDoctor; i++) {
		Doctor *doc = new Doctor(/*&records,*/ &patientQueue20, &patientQueue10, &stats);
		caregivers.push_back(doc);
	}
	for (int i = 0; i < numNurse; i++) {
		Nurse *nur = new Nurse(/*&records,*/ &patientQueue10, &stats);
		caregivers.push_back(nur);
	}

}
