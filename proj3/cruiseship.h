// language: C++
// author: Vanessa Serao

// This is the derived cruiseship class interface "cruiseship.h" file 

#include <string>
#include <iostream>
#include "ship.h"
#ifndef CRUISESHIP_H
#define CRISESHIP_H
using namespace std;


class Cruiseship : public Ship
{
	private:
		double percentage_lux ;
		double percentage_upper ;
		double percentage_lower ;
		
		int numOfPassLux;
		int numOfPassUpper;
		int numOfPassLower;
		
	public:
		// A five parameter constructor that takes the ship’s name, fuel load, and the percentages of passengers
		//in Luxury, Upper Deck, and Lower Deck
		Cruiseship(string shipName, double fuelLoad, double percentagePassLux, double percentagePassUpper, double percentagePassLower);

		//function that overrides the virtual function in the base class, and prints a message indicating that 
		//the cruise ship is underway, with a break down of the number of passengers in each
		void sail(); 

		// function that accepts an integer representing the number of passengers as
		//a parameter,and distributes those passengers among the three cabin levels
		void load(int numOfPass);
};
#endif







