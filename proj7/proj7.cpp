// language: C++
// author: Vanessa Serao

#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include "card.h"
#include "priorityqueue.h"
using std::string;
using std::cout;
using std::endl;

int main()
{

	// instantiate  max priority queue
	// pq <card, comp> mymaxqueue
	PriorityQueue <Card, MaxHeap<Card> > maxQueue;

	//min priority queue
	PriorityQueue <Card, MinHeap<Card>> minQueue;

	// instantiate an array of 13 cards in the spades suit
	//Card cards(13, spades);

	std::vector<Card> cards;
	for (int i = 1; i <= 13; i++)
		cards.push_back(Card(i, spades));

	//for (int i = 0; i < 13; i++)
		//cout << cards[i] << " ";
	//cout << endl;

	// shuffle the cards in array using std::random_shuffle()
	std::random_shuffle(cards.begin(), cards.end());

	//for (int i = 0; i < 13; i++)
		//cout << cards[i] << " ";
	//cout << endl;


	//**** MaxQueue ****// 

	// enqueue the first seven cards in the max priority queue and display the heap's contents after each enqueue
	for (int i = 0; i < 7; i++)
	{
		cout << "Enqueuing " << cards[i] << "\n" << "\t";
		maxQueue.enqueue(cards[i], MaxHeap<Card>{});
		maxQueue.print();
		cout << endl;
	}
	cout << endl;

	// dequeue each card individually from the max priority queue until it's empty - display the heap's contents after each dequeue


	for (int i = 0; i < 7; i++)
	{
		maxQueue.dequeue(MaxHeap<Card>{});
		maxQueue.print();
		cout << endl;
	}
	cout << "Max Heap is empty.\n";
	cout << endl;

	//**** MinQueue ****// 

	// enqueue the remaining six cards in the min priority queue and display the heap's contents after each enqueue

	for (int j= 7; j < 13; j++)
	{
		cout << "Enqueuing "<< cards[j] << "\n" << "\t";
		minQueue.enqueue(cards[j], MinHeap<Card>{});
		minQueue.print();
		cout << endl;
	}
	cout << endl;

	// dequeue each card individually from the min priority queue until it's empty - display the heap's contents after each dequeue
	for (int j = 7; j < 13; j++)
	{
		minQueue.dequeue(MinHeap<Card>{});
		minQueue.print();
		cout << endl;
	} 
	cout << "Min Heap is empty.\n";
	cout << endl;

	system("pause");
	return 0;
	
}