// language: C++
// author: Vanessa Serao

#include <string>
#include <iostream>
#ifndef GASPUMP_H
#define GASPUMP_H
using namespace std;


class GasPump
{
	private:
		string typeOfGas; //contains the type of gas the gas pump holds
		double amountOfFuelOnHand; //   the amount of fuel on hand(in gallons)
		double pumpCapacity; //   the fuel pump’s capacity(in gallons)
		double pricePerGallon; //  holds the price per gallon
		double fuelDispensedPerPurchase; // the amount of fuel dispensed per purchase
		double totalFuelDispensed; // the total amount of fuel dispensed(all purchases)
		double totalMoneyCollected; // stores the total amount of money collected(all purchases)
		bool nextCustomer; // indicates whether the next customer should be turned
						   // away as fuel is replenished
		void replenish(); // A function that replenishes the fuel pump’s tank when it runs out of fuel
	
	public:

		// A single constructor with three parameters 
		GasPump(string typeOfGas, double pumpCapacity, double pricePerGallon);

		// inline accessor function that returns a standard string for the pump’s fuel type
		string getFuelType() const
		{
			return typeOfGas;
		}

		// inline accessor function that returns the total amount of fuel dispensed(all purchases)
		double getTotalAmountOfFuel() const
		{
			return totalFuelDispensed;
		}

		//inline accessor function that returns the total amount of revenue collected(all purchases)
		double getTotalMoneyCollected() const
		{
			return totalMoneyCollected;
		}

		//controls the fueling of vehicles
		void dispenseFuel( double numberGallonsRequested);

};
#endif


	
	
	
	
	