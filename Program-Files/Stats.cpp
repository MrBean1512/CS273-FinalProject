#include "Stats.h"

Stats::Stats()
{
}

void Stats::update_report(Citizen * citizen)	//updated with new stats every time a patient is done being treated
{
	++num_patient;
	num_total_time = num_total_time + (citizen->dismissal_time - citizen->arrival_time);
	records.insert(std::pair<int, Citizen*>(citizen->it, citizen));
}

void Stats::print_report()	//prints statistics at the end of the program
{
	std::cout << "Total patients: " << num_patient << std::endl;
	std::cout << "Average Total Service time: " << (double)num_total_time / num_patient << std::endl;

	//user may view individual patient reports if they choose to
	bool search;
	std::cout << "Would you like to view the records for treated patients?\nEnter 0 if no or 1 if yes" << std::endl;
	std::cin >> search;
	if (search) {
		std::map<int, Citizen*>::iterator it;	//used a map here but a loop to print out each patient's info from the population vector would be better
		for (auto const& pair : records) {
			std::cout << "{" << pair.first << ": " << pair.second << "}\n";	//could not get this to print the string, would only print pointers, still needs work
		}
		int who=0;
		while (who != -1) {
			std::cout << "Enter the number of the person who's records you would like to view: ";
			std::cin >> who;
			it = records.find(who);
			std::cout << records.find(who)->second->records[0];
			std::cout << "Would you like to search another record?\nEnter -1 to exit and 0 to continue";
			std::cin >> who;
		}

	}
	return;
}