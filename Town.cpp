#include "Town.h"

Town::Town(int numDoctor, int numNurse)
{
	ER myER(population, numDoctor, numNurse);
}

void Town::update(int prob)
{
	bool strike = (rand() % 60 < prob);
	if (strike == false)
		return;

}
