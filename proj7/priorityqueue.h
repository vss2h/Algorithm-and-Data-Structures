// language: C++
// author: Vanessa Serao

#pragma once


#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include "card.h"
using std::string;
using std::cout;
using std::endl;
using std::vector;

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

// This class represents a priority queue implemented as a binary heap. It has
// two type parameters : 1) The type of the element stored in the heap 2) A comparator class.
template <typename EleStoredType, typename Comparator>

// stores items and restricts accesses to the
// highest priority item
class PriorityQueue
{
public:
	// resize the vector representing the heap to hold 50 items
	PriorityQueue()
	{
		heapArr.resize(50);
	}

	// returns the highest priority item in the heap. does not change the heap
	int top(EleStoredType index)
	{
		// return the root
		int parent= (index - 1) / 2;

		return heapArr[parent];
	}

	// has a comparator parameter. removes the highest priority item in the heap
	void dequeue(Comparator cmp)
	{
		cout << "Dequeuing " << heapArr[0] << "\n" << "\t";
		
		//replace parent with last child in heap
		// removes the last element in vector
		heapArr[0] = heapArr[size - 1];

		//heapArr[size - 1] = heapArr[size];

		// reduces the container size by one
		size--;

		//heap down
		heapDown(0, cmp);

	}

	// enqueues the item and places it in the heap in priority order
	void enqueue(EleStoredType item, Comparator cmp)
	{
		// insert item at size
		// put the item at the end of the heap
			heapArr[size] = item;
			size++;

			// heap up
			heapUp(size - 1, cmp);
	}

	// displays the items in the heap, from index 0 through index size-1
	void print()
	{
		if (size == -1)
			cout << "is empty";
		else
			for (int i = 0; i < size; i++)
				cout << heapArr[i] << ' ';
	}

private:

	vector<EleStoredType> heapArr;
	int size = 0;

	// percolates the item up based on its priority
	void heapUp(int index, Comparator cmp)
	{
		// parent
		int parent = (index - 1) / 2;
	
		// base case
		if (index == 0 || cmp.HighPriority(heapArr[parent], heapArr[index]))
			return;
		
		// while the element is not the parent and the index is greater than or equal to the parent's element
		// swap the element with its parent
		// call the  recursive function
		if (cmp.HighPriority(heapArr[index], heapArr[parent]))
		{
			EleStoredType temp = heapArr[parent];
			heapArr[parent] = heapArr[index];
			heapArr[index] = temp;

			//cout << "Heap Up HERE \n";
			heapUp(parent, cmp);
		}

	}

	// percolates the item down based on its priority
	void heapDown(int index, Comparator cmp)
	{
		int left_child = (index * 2) + 1;
		int right_child = (index * 2) + 2;
		

		// base case
		if (left_child > size)
			return;

		int largest = index;
		// check if the left child is the largest
		if (cmp.HighPriority(heapArr[left_child], heapArr[index]))
			largest = left_child;

		// check if the right child is the largest
		if (right_child < size && (cmp.HighPriority(heapArr[right_child], heapArr[largest])))
			largest = right_child;

		// swap
		if (largest != index)
		{
			EleStoredType temp = heapArr[index];
			heapArr[index] = heapArr[largest];
			heapArr[largest] = temp;

			//cout << "Heap Down HERE \n";
			heapDown(largest, cmp);
		}
	}

};


// first templated class comparator that take a type parameter bool 
template <typename EleStoredType>

class MinHeap
{
public:
	// returns if the item is less than or equal (<=) to the other one
	bool HighPriority(const EleStoredType &lhs, const EleStoredType &rhs) const
	{
		return (lhs <= rhs);
	}
};

// Second templated class comparator that take a type parameter bool
template <typename EleStoredType>

class MaxHeap
{
public:
	// returns if the item is less than or equal (<=) to the other one
	bool HighPriority(const EleStoredType &lhs, const EleStoredType &rhs) const
	{
		//cout << "in cmp " << lhs << " " << rhs << "\n";
		return (lhs >= rhs);
	}
};


#endif