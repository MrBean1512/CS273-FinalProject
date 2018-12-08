#include <iostream>
#include <vector>

#ifndef RECORD_H_
#define RECORD_H_

class Record {
private:
	int treatmentTime;
	int sicknessLevel;
public:

	int getTreatmentTime() { return treatmentTime; }
	int getSicknessLevel() { return sicknessLevel; }
};

#endif