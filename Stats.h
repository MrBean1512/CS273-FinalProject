#include <map>

#include "Citizen.h"
#include "Record.h"

#ifndef STATS_H_
#define STATS_H_

class Stats
{
private:
	int num_patient=0;
	int num_wait_time=0;
	int num_total_time=0;

public:
	Stats() : num_patient(0), num_wait_time(0), num_total_time(0){}
	std::map<int, Citizen*> records;

	void update_report(Citizen *citizen);
	void print_report();

};

#endif
