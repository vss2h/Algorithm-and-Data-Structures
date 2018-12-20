// language: C++
// author: Vanessa Serao

#include "maze.h"
#include <iostream>
#include <fstream>
#include <stdlib.h> 
using std::cout;
using std::cin;
using std::endl;

int main()
{
	srand(1000);
	std::ifstream myFile;
	bool success = false;
	myFile.open("maze.txt");

	Maze myMaze(myFile);
	myMaze.Print();

	Coordinate mc = myMaze.GetStartPt();
	cout << "Starting position: " << mc.x +1 << "," << mc.y +1 << endl;
	myMaze.FindExit(mc.x, mc.y, success);

	//myMaze.FindExit(4, 3, success);

		if (!exit)
			cout << "Unable to find exit!" << endl;
		else
			cout << "Found Exit!" << endl;
		
		system("pause");
		return 0;
}