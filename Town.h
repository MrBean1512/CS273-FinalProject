#include <iostream>
#include <vector>

#include "ER.h"
#include "Citizen.h"

#ifndef TOWN_H_
#define TOWN_H_

class Town {
private:
	
public:
	Town(int numDoctor, int numNurse);

	std::vector<Citizen*> population;
	void update(int prob);
};

#endif