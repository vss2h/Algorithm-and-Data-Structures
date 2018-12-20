// language: C++
// author: Vanessa Serao

// This is the derived cargoship class interface "cargoship.h" file 

#include <string>
#include <iostream>
#include "ship.h"

#ifndef CARGOSHIP_H
#define CARGOSHIP_H
using namespace std;

// definition for the derived class cargo ship
class Cargoship : public Ship
{
	private:
		
		double* fwdTonnage ;
		double* aftTonnage;
		int cargo_capacity;
	

	public:
		//A three parameter constructor that takes the ship’s name, fuelload, and cargo capacity
		Cargoship(string shipName, double fuelLoad, double cargoCapacity);
		
		//A destructor that frees the memory  allocated for the cargo bays
		~Cargoship();
		
		void fuel(int); //A void function,fuel, that overloads the function in the base class, 
		
		void load(int cargo);//function that accepts an integer representing the tons of cargo to beloaded on the ship –
		
};
#endif







