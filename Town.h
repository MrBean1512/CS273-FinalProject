#include <iostream>
#include <vector>

#include "Citizen.h"

#ifndef TOWN_H_
#define TOWN_H_

class Town {
private:
	bool strike = false;
public:

	std::vector<Citizen> population;
	void update();
};

#endif