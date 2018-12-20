// language: C++
// author: Vanessa Serao

// This is the class interface "ship.h" file 

#include <string>
#include <iostream>
#ifndef SHIP_H
#define SHIP_H
using namespace std;


class Ship
{
	protected:
			string ship_name; //	A string containing the ship’s name
			double amount_fuel; //	A double representing the amount of fuel on board(in tons)
	
	public:
			Ship(string shipName, double fuelLoad); //	A two parameter constructor that takes the ship’s name and fuel
												//	load(in that order)
			void fuel(); //	A void function that outputs the ship’s name and its fuel load
			void virtual sail();//	virtual function that prints a generic message indicating that the ship is underway
			void virtual load(int) = 0; //	A pure - virtual void function,
								//that loads the ship with tonnage(cargo) or passengers(cruise)
};

#endif




