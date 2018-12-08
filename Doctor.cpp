#include "Doctor.h"
#include "ER.h"

void Doctor::update()
{
	if (curPatient == nullptr) {
		if (treatmentTime > 1)
			treatmentTime--;
		else {
			//put patient back into citizens vector
		}
	}
	else {	//retrieve the next patient and assign them a random treatmentTime ranging 1-20
		if (ER.patientQueue20.size > 0) {
			//search this queue first
		}
		else if (ER.patientQueue15.size > 0) {
			//then this queue
		}
		else if (ER.patientQueue10.size > 0) {
			//then this queue
		}
		else {
			//if there is no one in line, do nothing
		}
	}
}
