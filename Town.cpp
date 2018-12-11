#include "Town.h"
#include "ER.h"
#include <time.h>

Town::Town(int sickRate, int numDoctor, int numNurse)
{
	this->sickRate = sickRate;
	numDoc = numDoctor;
	this->numNurse = numNurse;

	ER newER(numDoctor, numNurse);
	myER = newER;
	// some other value
	//ER *thisER = new ER(numDoctor, numNurse);//
	//this->myER = ER(numDoctor, numNurse);
	
}

void Town::update(int i)
{
	//srand(time(0));	//consider pasing i into rand
	std::cout << "The address of pt10 is " << &myER.getPatientQueue10() << ", and the address of pq20 is " << &myER.getPatientQueue20() << std::endl;

	bool strike = (rand() % 60 < sickRate);	//does someone get sick?
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
	population[who]->setSicknessSeverity(sick);
	if (sick <= 10 && sick > 0) {
		myER.patientQueue10.push(population[who]);
	}
	else {
		myER.patientQueue20.push(population[who]);
	}
	population[who]->arrival_time = i;

}
