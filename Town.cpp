#include "Town.h"
#include "ER.h"
#include <time.h>

Town::Town(int sickRate, int numDoctor, int numNurse)
{
	this->sickRate = sickRate;
	ER *thisER = new ER(numDoctor, numNurse);
	myER = *thisER;
}

void Town::update(int i)
{
	srand(time(0));	//consider pasing i into rand
	bool strike = (rand() % 60 < sickRate);	//does someone get sick?
	strike = true; //remove this
	if (strike == false)
		return;

	int sick = (rand() % 100);	//if so then strike them with a sicknessSeverity
	if (sick < 10) {
		sick = ((rand() % 5) + 15);
	}
	else if (sick < 30) {
		sick = ((rand() % 5) + 10);
	}
	else {
		sick = (rand() % 10);
	}

	int who = (rand() % population.size());	//choose who gets sick
	if (population[who]->flag == true)
		return;
	if (sick <= 10 && sick > 0) {
		myER.patientQueue10.push(population[who]);
	}
	else {
		myER.patientQueue20.push(population[who]);
	}
	population[who]->arrival_time = i;

}
