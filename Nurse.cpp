#include "Nurse.h"

void Nurse::update()
{
	if (curPatient.size > 0) {
		if (treatmentTime > 1)
			treatmentTime--;
		else {
			//put patient back into citizens vector
		}
	}
	else {	//retrieve the next patient and assign them a random treatmentTime ranging 1-20
		if (ER.patientQueue10.size > 0) {
			//search this queue first
		}
		else {
			//if there is no one in line, do nothing
		}
	}
}
