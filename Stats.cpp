#include "Stats.h"

Stats::Stats()
{
}

void Stats::update_report(Citizen * citizen)
{
	++num_patient;
	num_total_time = num_total_time + (citizen->dismissal_time - citizen->arrival_time);
	records.insert(std::pair<int, Citizen*>(citizen->it, citizen));
}

void Stats::print_report()
{
	std::cout << "Total patients: " << num_patient << std::endl;
	std::cout << "Average Total Service time: " << (double)num_total_time / num_patient << std::endl;
}