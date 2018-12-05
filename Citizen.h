#include <iostream>
#include <vector>

#ifndef CITIZEN_H_
#define CITIZEN_H_

class Citizen {
private:
	std::string name;
	int numVisits;
	std::vector<int> sickness;
public:

	int getNumVisits();
};

#endif