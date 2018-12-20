// language: C++
// author: Vanessa Serao

// This is the base class implementation "ship.cpp" file

#include <iostream>
#include <string>
using namespace std;
#include "ship.h"

//	A two parameter constructor that takes the ship’s name and fuel load(in that order)
Ship::Ship(string shipName, double fuelLoad)
{
	ship_name = shipName;
	amount_fuel = fuelLoad;
}
//	A void function that outputs the ship’s name and its fuel load
void Ship:: fuel()
{
	cout << ship_name << " fuel" << ": " << amount_fuel << " tons" << endl;
}
//	virtual function that prints a generic message indicating that the ship is underway
void Ship:: sail()
{
	cout << "Ship sailing " << endl;
}

