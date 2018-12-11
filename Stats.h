#include <map>
#include <vector>

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

	std::vector<Citizen*> *population;

public:
	Stats();
	std::map<int, Citizen*> records;

	void update_report(Citizen *citizen);
	void print_report();

};

#endif
