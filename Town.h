#include <iostream>
#include <vector>

#include "ER.h"
#include "Citizen.h"

#ifndef TOWN_H_
#define TOWN_H_

class Town {
private:
	int sickRate=0;
public:
	Town(int sickRate, int numDoctor, int numNurse);

	ER myER;
	std::vector<Citizen*> population;

	void update(int i);
};

#endif