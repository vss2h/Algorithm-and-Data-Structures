// language: C++
// author: Vanessa Serao

#include <iostream>
#include <cstdlib>
#include <string>
#include "GasPump.h"

using namespace std;

int main()
{
	GasPump unleaded("Unleaded", 200, 2.59);
	GasPump midgrade("Midgrade", 125, 2.87);
	GasPump	premium("Premium+", 100, 3.13);
		
	//Declare a pointer to a GasPump object(will be used to select which pump a vehicle will use)
	GasPump* pumpPtr = nullptr;
	
	//Set the random number generator seed to 1000 
	srand(1000);
	double reqFuel;
	int rnd, var;
	
	//Create a for loop to simulate 50 vehicles
	for (int i = 0; i < 50; i++)
	{
		pumpPtr = &unleaded; //Set the pointer to the unleaded pump
		int rnd = rand(); //Draw a random number 
		var = rnd % 7;
		if (var == 4 || var == 5)
		{
			pumpPtr = &midgrade;
		}
		else
		if (var == 6)
		{
			pumpPtr = &premium;
		}
			
		//Determine the amount of fuel the vehicle requires
		reqFuel = 3 + (((double)rnd) / RAND_MAX) * 22;
		cout << "Vehicle " << i + 1 << " ";
		
		//Use the pointer to invoke the dispenseFuel function for the appropriate pump
		pumpPtr->dispenseFuel(reqFuel);
	}
	pumpPtr = &unleaded;
	
	cout << "Pump " << pumpPtr->getFuelType()<<" dispensed " << pumpPtr ->getTotalAmountOfFuel() << " gallons and collected " << pumpPtr->getTotalMoneyCollected() << endl;
	pumpPtr = &midgrade;
	cout << "Pump " << pumpPtr->getFuelType() << " dispensed " << pumpPtr->getTotalAmountOfFuel() << " gallons and collected " << pumpPtr->getTotalMoneyCollected() << endl;
	pumpPtr = &premium;
	cout << "Pump " << pumpPtr->getFuelType() << " dispensed " << pumpPtr->getTotalAmountOfFuel() << " gallons and collected " << pumpPtr->getTotalMoneyCollected() << endl;
	system("pause");
	return 0;
}



	
