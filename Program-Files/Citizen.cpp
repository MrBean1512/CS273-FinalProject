#include "Citizen.h"

Citizen::Citizen(std::string Name)
{
	name = Name;
}

int Citizen::getSicknessSeverity()
{
	return sicknessSeverity;
}

void Citizen::setSicknessSeverity(int s)
{
	sicknessSeverity = s;
}

void Citizen::decrementSicknessSeverity()
{
	sicknessSeverity--;
}
