#include <iostream>
#include <vector>

#include "ER.h"
#include "Citizen.h"

#ifndef TOWN_H_
#define TOWN_H_

class Town {
private:
	int sickRate=0;
	int numDoc;
	int numNurse;

	//ER testER;
public:
	Town(int sickRate, int numDoctor, int numNurse);

	//ER *myER = new ER(numDoc, numNurse);
	ER *myER;
	std::vector<Citizen*> population;

	void update(int *i);

	//void setER(ER emRoom) {
	//	this->testER = emRoom;
	//}
};

#endif