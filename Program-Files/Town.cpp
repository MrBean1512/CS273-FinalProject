#include "Town.h"
#include "ER.h"
#include <time.h>

Town::Town(int sickRate, int numDoctor, int numNurse)
{
	this->sickRate = sickRate;

	//I kept the commented code below to show how many different things we tried in order to have the most efficient code
	//the uncommented code at the end was the only thing that worked even though they are all very similar
	//each of the other options created entirely different ER objects that could never be accessed
	//this was the root of one single problem that took 12 hours to figure out

	//ER newER(numDoctor, numNurse);
	//myER = newER;
	// some other value
	//ER *thisER = new ER(numDoctor, numNurse);//
	//this->myER = ER(numDoctor, numNurse);

	myER = new ER(numDoctor, numNurse);
	
}

void Town::update(int *i)
{
	//srand(time(0));	//consider pasing i into rand
	//std::cout << "The address of pt10 is " << &myER->getPatientQueue10() << ", and the address of pq20 is " << &myER->getPatientQueue20() << std::endl;
	//part of our debugging process to get our pointers to work better

	bool strike = (rand() % 60 < sickRate);	//decides whether or not anyone even gets sick
	if (strike == false)
		return;

	int sick = (rand() % 100);	//if someone is sick, then strike them with a random sicknessSeverity	//the sick integer is recycled in each if statement
	if (sick < 10) {		//10% chance to get an ailment between 16-20
		sick = ((rand() % 5) + 15);
	}
	else if (sick < 30) {	//20% chance to get an ailment between 11-15
		sick = ((rand() % 5) + 10);
	}
	else {					//70% chance to get an ailment between 1-10
		sick = (rand() % 10);
	}

	int who = (rand() % population.size());	//randomly decides who gets sick from the population vector of citizen objects
	if (population[who]->flag == true)	//if the person is already sick then don't bother doing anything
		return;
	population[who]->setSicknessSeverity(sick);	//if they aren't already sick, update their sickness level and then assign them a priority queue
	if (sick <= 10 && sick > 0) {
		myER->patientQueue10.push(population[who]);
	}
	else {
		myER->patientQueue20.push(population[who]);
	}
	population[who]->arrival_time = *i;	//set the arrival time which will be relevant until it is passed into stats.update function

}
