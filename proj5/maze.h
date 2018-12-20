// language: C++
// author: Vanessa Serao

#ifndef MAZE_H
#define MAZE_H
#include <fstream> 
#include <vector>


struct Coordinate										// 2D point consisting of x and y coordinates
{
	double x, y;
	Coordinate(double px, double py) : x(px), y(py) {}	// Constructor with initializer list
};


class Maze								// Represents Maze class' data and function members
{
public:
	Maze(std::ifstream&);				// Constructor: takes file object and reads maze map from file
	void Print();						// Displays the maze and its state
	Coordinate GetStartPt();			// Returns a randomly chosen maze starting point - use coords member
	void FindExit(int, int, bool&);		// Recursive function that attempts to find the exit
private:
	char maze[10][10];					// 2D array that holds maze - outer columns and rows not traversable
	int maxRows; 						// Maximum number of rows - excludes outer walls
	int maxCols; 						// Maximum number of columns - excludes outer walls
	std::vector<Coordinate> coords;		// holds initially traversable locations on the map
};

#endif