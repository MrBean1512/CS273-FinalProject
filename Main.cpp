#include <iostream>
#include <fstream>
#include <string>

#include "ER.h"
#include "Citizen.h"
#include "Town.h"

using std::cout;
using std::cin;
using std::endl;

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
	while (myfile)	//read txt file
	{
		std::string sinput;
		myfile >> sinput;
		myTown.population.push_back(new Citizen(sinput));
	}

	//run the simulation
	cout << "Done." << endl;
	int runtime = 10080;	//60x24x7
	cout << "Running simulation for " << runtime << " ticks..." << endl;
	for (int i = 0; i < runtime; ++i)
	{
		myTown.update(i);
		for (int i = 0; i < myTown.myER.caregivers.size(); i++)
			myTown.myER.caregivers[i]->update(i);
	}

	//output the report
	//don't forget to track statistics

	cout << "finished" << endl;

	return 0;

}