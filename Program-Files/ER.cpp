#include "ER.h"

ER::ER()
{
}

ER::ER(int numDoctor, int numNurse)
{
	//set the patient queues
	setPatientQueue10(patientQueue10);
	setPatientQueue20(patientQueue20);

	//loops take in user input variables and creates the respective number of caregivers and places them into the caregiver vectors
	for (int i = 0; i < numDoctor; i++) {
		std::cout << "The address of pttest10 is " << &patientQueue10 << ", and the address of pqtest20 is " << &patientQueue20 << std::endl;
		Doctor *doc = new Doctor(&patientQueue20, &patientQueue10, &stats);
		caregivers.push_back(doc);
	}
	for (int i = 0; i < numNurse; i++) {
		Nurse *nur = new Nurse(&patientQueue10, &stats);
		caregivers.push_back(nur);
	}
}
