/*////////////////////////////////////////////
The stats class holds the overall statistics 
of the entire program
////////////////////////////////////////////*/
#include <map>
#include <vector>

#include "Citizen.h"
#include "Record.h"

#ifndef STATS_H_
#define STATS_H_

class Stats
{
private:
	int num_patient=0;		//total number of patients
	int num_total_time=0;	//total time taken to treat each patient combined
	int num_wait_time = 0;	//average wait time from arrival to dismissal of all treated patients (calculated from num_patient & num_total_time)

	std::vector<Citizen*> *population;	//pointer to the vector of citizen objects so that the map can properly access all patients' records

public:
	Stats();	//constructor

	std::map<int, Citizen*> records;	//used to access individual patients' records

	void update_report(Citizen *citizen);	//only run whenever a patient is dismissed
	void print_report();	//outputs report of treated patiens to the console

};

#endif
