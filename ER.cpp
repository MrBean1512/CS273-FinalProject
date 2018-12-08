#include "ER.h"

ER::ER(std::vector<Citizen*>* Population, int numDoctor, int numNurse)
{
	population = Population;
	for (int i = 0; i < numDoctor; i++) {
		Doctor *doc = new Doctor(Population);
		caregivers.push_back(doc);
	}
	for (int i = 0; i < numNurse; i++) {
		Nurse *nur = new Nurse(Population);
		caregivers.push_back(nur);
	}
}
