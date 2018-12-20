// language: C++
// author: Vanessa Serao

// This is the derived cruiseship class implementation "cruiseship.cpp" file

#include <iostream>
#include <string>
#include "ship.h"
#include "cruiseship.h"
using namespace std;


// A five parameter constructor that takes the ship’s name, fuel load, and the percentages of passengers
//in Luxury, Upper Deck, and Lower Deck(in that order) 
Cruiseship::Cruiseship(string shipName, double fuelLoad, double percentagePassLux, 
	double percentagePassUpper, double percentagePassLower) : Ship(shipName, 
		fuelLoad)
{
	ship_name = shipName;
	amount_fuel = fuelLoad;
	percentage_lux = percentagePassLux;
	percentage_lower = percentagePassLower;
	percentage_upper = percentagePassUpper;
}

//function that overrides the virtual function in the base class, and prints a message indicating that the cruise ship 
//is underway, with a break down of the number of passengers in each cabin level
void Cruiseship:: sail()
{
	cout << ship_name << " sailing: " << numOfPassLux << " in Luxury " << numOfPassUpper 
		<< " in Upper Deck " << numOfPassLower << " in Lower Deck " << endl;
}

// function that accepts an integer representing the number of passengers as a parameter,and distributes those 
// passengers among the three cabin levels per the percentages specified

void Cruiseship:: load(int numOfPass)
{
	numOfPassLux = percentage_lux  * numOfPass;
	numOfPassUpper = percentage_upper * numOfPass;
	numOfPassLower = percentage_lower * numOfPass;
}
