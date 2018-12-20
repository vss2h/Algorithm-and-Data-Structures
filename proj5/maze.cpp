// language: C++
// author: Vanessa Serao

//Project: FIND YOUR WAY OUT!

#include "maze.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h> 
using std::cout;
using std::cin;
using std::endl;

// Constructor: takes file object and reads maze map from file
Maze::Maze(std::ifstream & inFile)
{
	char items;
	inFile >> maxRows;
	inFile >> maxCols;
	inFile >> items;

	// create maze
	// adjust maxrows and maxcols for Xs border
	maxRows += 2;
	maxCols += 2;

	// creating the top row border
	for (int i = 0; i < maxCols; i++)
		maze[0][i] = 'X';


	// creating the bottom row border
	for (int i = 0; i < maxCols; i++) 
		maze[maxRows - 1][i] = 'X';


	// creating the left column border
	for (int i = 0; i < maxRows; i++)
		maze[i][0] = 'X';

	//creating the right column border
	for (int i = 0; i < maxRows; i++)
		maze[i][maxCols - 1] = 'X';


	Coordinate cor(0, 0);
	for (int i = 1; i < maxRows-1; i++)
	{
		for (int j = 1; j < maxCols-1; j++)
		{
			maze[i][j] = items;
			inFile >> items;
		}
	}
	// add travesable cordinates into vector
	for (int i = 1; i < maxRows-1; i++)
	{
		for (int j = 1; j < maxCols-1; j++)
		{
			if (maze[i][j] == 'O')
			{
				cor.x = i;
				cor.y = j;
				coords.push_back(cor);
			}
		}
	}

	

}

// Displays the maze and its state
void Maze::Print()
{
	cout << "Maze state:" << endl;

	for (int x = 1; x < maxRows-1; x++)
	{
		for (int y = 1; y < maxCols-1; y++)
			cout << " " << maze[x][y];
		cout << endl;
	}
}

// Returns a randomly chosen maze starting point - use coords member
Coordinate Maze::GetStartPt()
{
	int pt, random;
	Coordinate O(0, 0);
	pt = rand() % coords.size();
	O = coords[pt];
	return O; 
	
	
}

// Recursive function that attempts to find the exit
void Maze::FindExit(int cur_x, int cur_y, bool& found)
{
	if (maze[cur_x][cur_y] == 'E' && !found)
	{
		found = true;
		cout << "Trying " << cur_x + 1 << "," << cur_y + 1 << endl;
		
	}

	if (!found)
	{
		maze[cur_x][cur_y] = '*';
		cout << "Trying " << cur_x + 1 << "," << cur_y + 1 << endl;
		Print();

		//Since the exit is not found,Check the next move
		// is either an opening (O) or the exit 

		// move up
		if (maze[cur_x][cur_y-1] == 'O' || maze[cur_x][cur_y-1] == 'E')
			FindExit(cur_x, cur_y - 1, found);
		
		//move down
		if (maze[cur_x][cur_y+1] == 'O' || maze[cur_x][cur_y + 1] == 'E')
			FindExit(cur_x, cur_y + 1, found);
		// move left
		if (maze[cur_x - 1][cur_y] == 'O' || maze[cur_x - 1][cur_y] == 'E')
			FindExit(cur_x - 1, cur_y, found);
		
		if (maze[cur_x + 1][cur_y] == 'O' || maze[cur_x + 1][cur_y] == 'E')
			FindExit(cur_x + 1, cur_y, found);
	}
	maze[cur_x][cur_y] = 'O'; 
	
}
