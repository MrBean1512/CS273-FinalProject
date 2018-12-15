/*////////////////////////////////////////////
The town class holds all of the other objects 
inside of it and it is our primary point of access
for the main function
////////////////////////////////////////////*/
#include <iostream>
#include <vector>

#include "ER.h"
#include "Citizen.h"

#ifndef TOWN_H_
#define TOWN_H_

class Town {
private:
	int sickRate=0;	//user input variable which dictates the probability that someone will get sick

public:
	Town(int sickRate, int numDoctor, int numNurse);	//constructor! yay!

	//ER *myER = new ER(numDoc, numNurse);	//old test for trying to construct an ER with proper pointers
	ER *myER;
	std::vector<Citizen*> population;	//vector where all citizen objects are stored

	void update(int *i);	//update function to decided if someone gets sick in that tick
	//the *i is used to set_arrival_time

	//more test code
	//void setER(ER emRoom) {
	//	this->testER = emRoom;
	//}
};

#endif