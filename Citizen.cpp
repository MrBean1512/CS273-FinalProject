#include "Citizen.h"

Citizen::Citizen(std::string Name)
{
	name = Name;

}

int Citizen::getNumVisits()
{
	return numVisits;
}
