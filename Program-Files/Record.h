/*////////////////////////////////////////////
Record objects holds information about individual 
visits which are stored in their respective 
citizen objects
////////////////////////////////////////////*/
#include <iostream>

#ifndef RECORD_H_
#define RECORD_H_

class Record {
private:
	int treatmentTime;	//total treatment time from arrival
	int sicknessLevel;
	int arrivalTime;
	int dismissalTime;

public:
	Record(int sicknessLevel, int arrivalTime, int dismissalTime);
	int getTreatmentTime() { return treatmentTime; }
	int getSicknessLevel() { return sicknessLevel; }
};

#endif