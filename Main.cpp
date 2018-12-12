#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include "ER.h"
#include "Citizen.h"
#include "Town.h"

using std::cout;
using std::cin;
using std::endl;

//consider having functions to measure runtime and then calculate it based on different times (ie what's the difference between 10080 and 1008000)

int main()
{
	std::ifstream myfile("Residents.txt");	//check if the txt file exists, if it doesn't terminate the program;
	if (!myfile)
	{
		std::cout << "Uh oh, the text file for residents could not be opened! Try again! " << std::endl;
		exit(1);
	}

	//enter user input variables
	int numDoctor;
	int numNurse;
	int sickRate;
	cout << "Enter the number of doctors you would like this simulation to run: ";
	cin >> numDoctor;
	cout << "Enter the number of nurses you would like this simulation to run: ";
	cin >> numNurse;
	cout << "Enter the average number of patients that will arrive per hour (will not run more than 60)";
	cin >> sickRate;

	//set everything up
	cout << "\nLoading files..." << endl;
	Town myTown(sickRate, numDoctor, numNurse);
	int assign = 0;
	while (myfile)	//read txt file
	{
		std::string sinput;
		myfile >> sinput;
		myTown.population.push_back(new Citizen(sinput));
		myTown.population.back()->it = assign;
		assign++;
	}

	//run the simulation
	cout << "Done." << endl;
	int runtime = 1008000;	//60x24x7
	cout << "Running simulation for " << runtime << " ticks..." << endl;
	srand(time(0));
	for (int i = 0; i < runtime; ++i)
	{
		myTown.update(&i);
		for (int j = 0; j < myTown.myER->caregivers.size(); j++)
			myTown.myER->caregivers[j]->update(&i);
	}

	

	//output the report
	myTown.myER->stats.print_report();

	cout << "finished" << endl;

	return 0;

}