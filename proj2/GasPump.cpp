// language: C++
// author: Vanessa Serao


#include <iostream>
#include <string>
#include "GasPump.h"
using namespace std;


//This function has three parameters that map directly to data members and 
//initialize the fuel quantity on hand to the maximum tank capacity
GasPump::GasPump(string typeofgas, double pumpcapacity, double pricepergallon) 
{
	typeOfGas = typeofgas;
	pumpCapacity = pumpcapacity;
	pricePerGallon = pricepergallon;
	amountOfFuelOnHand = pumpcapacity;
	totalFuelDispensed = 0; // the total amount of fuel dispensed(all purchases)
	fuelDispensedPerPurchase = 0; // the amount of fuel dispensed per purchase
	totalMoneyCollected = 0;
}

//This function should resets the fuel level to the maximum capacity, and outputs a
// message to that effect
void GasPump::replenish()
{
	 amountOfFuelOnHand = pumpCapacity;
	cout << typeOfGas << "Turned away (out of gas)...Tank replenished." << endl;
	nextCustomer = true;
}

//This function controls the fueling of a single vehicle.It
//accepts a double argument that indicates the number of gallons requested by the vehicle.

void GasPump::dispenseFuel(double numberOfGallonsRequested)
{
	cout << std::fixed;
	cout.precision(2);
	double cost = 0;

	if (nextCustomer)
	{
		if (numberOfGallonsRequested < amountOfFuelOnHand)
		{
			cost = pricePerGallon*numberOfGallonsRequested;
			cout << typeOfGas << " Filled up with " << numberOfGallonsRequested << " gallons " << cost << endl;

			totalFuelDispensed += numberOfGallonsRequested;
			amountOfFuelOnHand -= numberOfGallonsRequested;
			nextCustomer = true;

		}
		else
		{
			cost = pricePerGallon *amountOfFuelOnHand;
			cout << typeOfGas << " pumped " << amountOfFuelOnHand << " of " << numberOfGallonsRequested << " gallons " << cost << endl;
			nextCustomer = false;
			totalFuelDispensed += amountOfFuelOnHand;
			amountOfFuelOnHand = 0;
			
		}
		
	}
	else
		replenish();
		totalMoneyCollected += cost;
}
	
