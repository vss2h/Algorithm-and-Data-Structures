//Mezmur Zedawit
//CSCI 3110 - 001
//Project #1
//Due : 09 / 08 / 17

// This program takes size of an array from a user and icnreases the size of the array dynamicaly as needed.

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int* makeArray(int * arrayPtr, int num, double multiplier); // creates dynamic array
double calcAvg(int *myArray, int num); // calculates the average of the elements insude the array

int main()
{
	int size;
	double avg; // average
	double multiplier = 1.5; // increases the size of the array
	int* arrayPtr = NULL;
	
	cin >> size; // is initial extent of arrray

	if (size % 50 != 0 || size < 100 || size > 300) // checks for proper input values
	{
		cout << "Invalid input" << endl;
		exit(1);
	}
	arrayPtr = makeArray(arrayPtr, size, 1);
	// open and process files
	ifstream inFile;
	ofstream outFile;
	inFile.open("nums.txt");
	outFile.open("out.txt");
	int value;
	int count = 0;

	cout << "Allocated " << size << " elements" << endl;
	outFile << "Allocated " << size << " elements" << endl;

	inFile >> value;
	// read in values one line at a time
	while (inFile)
	{

		arrayPtr[count] = value; // read  values into the array
		count++;
		if (count >= int(size*.95) + 1)
		{
			avg = calcAvg(arrayPtr, count); // calculate average
			arrayPtr = makeArray(arrayPtr, size, multiplier); // create array
			size *= multiplier;
			if (size > 600)
			{
				size = 600;
			}
			cout << "Array size now " << size << " - Average so far is " << avg << endl; // print size and average
			outFile << "Array size now " << size << " - Average so far is " << avg << endl; // write size and average to file

		}

		inFile >> value;
	}
	avg = calcAvg(arrayPtr, count); // calculate average for last value
	cout << count << " integers were read and the average was " << avg << endl; // print size and average
	outFile << count << " integers were read and the average was " << avg; // write size and average to file
	delete[] arrayPtr; // delete dynamically created array
	inFile.close(); // close input file
	outFile.close(); // close output file

	system("pause");
	return 0;

}

int *makeArray(int* arrayPtr, int size, double multiplier) // make array function implementation
{
	int newSize = size *multiplier; 
	if (newSize > 600) // guard for the max size of the array
	{
		newSize = 600;
	}

	int* tempArray = NULL; // creates new array
	if (arrayPtr == NULL)
	{
		tempArray = new int[newSize];
	}
	else
	{
		tempArray = new int[newSize];
		for (int i = 0; i < size; i++)
			tempArray[i] = arrayPtr[i]; // copy contents of old array into new array
		delete[] arrayPtr; // delete old array
	}

	return tempArray;
}

double calcAvg(int *myArray, int num) // calculate average function implementation
{
	double sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += myArray[i];
	}
	return  sum / num;
}
