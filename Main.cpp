#include <iostream>
#include <fstream>
#include <string>

#include "ER.h"
#include "Citizen.h"
#include "Town.h"

int main()
{
	std::ifstream myfile("Residents.txt");

	if (!myfile)
	{
		std::cout << "Uh oh, this file could not be opened! Try again! " << std::endl;
		exit(1);
	}
	Town myTown;
	while (myfile)
	{
		std::string sinput;
		myfile >> sinput;
		//std::cout << sinput << std::endl;
		myTown.population.push_back(Citizen(sinput));
	}
	int runtime = 10080;
	for (int i = 0; i < runtime; ++i)
	{
		for (int i = 0; i < myER.caregivers.size; )
	}
	return 0;

}