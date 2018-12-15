#include "Caregiver.h"


int Caregiver::getTreatmentTime()
{
	return treatmentTime;
}

void Caregiver::setTreatmentTime(int t)
{
	treatmentTime = t;
}

void Caregiver::decrementTreatmentTime()
{
	treatmentTime--;
}
