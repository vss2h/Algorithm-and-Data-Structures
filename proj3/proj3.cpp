// language: C++
// author: Vanessa Serao

// This is the driver "proj3.cpp" file 

#include <iostream>
#include <cstdlib>
#include <string>
#include "ship.h"
#include "cruiseship.h"
#include "cargoship.h"
using namespace std;

// prototype for sailShip function
void sailShip(Ship& shipObject);


int main()
{
	//create an object of cruise ship type
	Cruiseship cruise("Carnival", 400, 0.1, 0.2, 0.7);
	cruise.fuel();
	cruise.load(5000);
	sailShip(cruise);

	//create an object of cargo shiptype
	Cargoship cargo("Iron Maiden", 750, 1000);
	Ship* shipObject = &cargo;
	shipObject->fuel();
	cargo.fuel(55);
	cargo.load(800);
	sailShip(cargo);
	
	
	system("pause");
	return 0;
}

//This function simulates the ship getting underway with a single call to the sail function
void sailShip(Ship& shipObject)
{
	shipObject.sail();
}




