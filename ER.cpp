#include "ER.h"

ER::ER()
{
}

ER::ER(int numDoctor, int numNurse)
{

	std::priority_queue<Citizen*> patientQueue10;
	std::priority_queue<Citizen*> patientQueue20;

	// set the patient Q's
	setPatientQueue10(patientQueue10);
	setPatientQueue20(patientQueue20);

	//std::priority_queue<Citizen*> pq10 = getPatientQueue10();
	for (int i = 0; i < numDoctor; i++) {
		std::cout << "The address of pttest10 is " << &patientQueue10 << ", and the address of pqtest20 is " << &patientQueue20 << std::endl;
		Doctor *doc = new Doctor(/*&records,*/ &patientQueue20, &patientQueue10, &stats);
		caregivers.push_back(doc);
	}
	for (int i = 0; i < numNurse; i++) {
		Nurse *nur = new Nurse(/*&records,*/ &patientQueue10, &stats);
		caregivers.push_back(nur);
	}
}
