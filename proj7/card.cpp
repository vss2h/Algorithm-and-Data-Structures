// language: C++
// author: Vanessa Serao

#include <iostream>
#include <queue>
#include <cassert>
#include <string>
#include "card.h"
#include "priorityqueue.h"
using std::string;
using std::cout;
using std::endl;


//constructor that takes a card's face (represented an integer) and suit
// card face example: Ace=0, 2=1, 3=2, ... Q=11, K=12 or some other ordering

Card::Card()
{}

Card::Card(int face, suit st)
{
	cardSuit = st;
	cardFace = face;

}

// overload the << operator to display the card
std::ostream& operator << (ostream& os, const Card& cd)
{
	char suit = cd.cardSuit;	//holds the card's suit

								// print suit symbol
	if (suit == hearts)
		suit = 'H';
	else if (suit == diamonds)
		suit = 'D';
	else if (suit == clubs)
		suit = 'C';
	else if (suit == spades)
		suit = 'S';

	// prints the cardFace and cardSuit 
	if (cd.cardFace == 1)
		os << "A" << suit << "[" << cd.cardFace << "]" << " ";
	else if (cd.cardFace > 1 && cd.cardFace <= 10)
		os << cd.cardFace << suit << "[" << cd.cardFace << "]" << " ";
	else if (cd.cardFace == 11)
		os << "J" << suit << "[" << cd.cardFace << "]" << " ";
	else if (cd.cardFace == 12)
		os << "Q" << suit << "[" << cd.cardFace << "]" << " ";
	else if (cd.cardFace == 13)
		os << "K" << suit << "[" << cd.cardFace << "]" << " ";
	return os;
}

// compare and return true if *this has a lesser point value than cd, false otherwise
bool Card:: operator <= (const Card& cd) const
{
	if (cardFace <= cd.cardFace)
		return true;
	else
		return false;
}

// compare and return true if *this has a larger point value than cd, false otherwise
bool Card:: operator >= (const Card& cd) const
{
	if (cardFace >= cd.cardFace)
		return true;
	else
		return false;
}

// compare and return true if *this has the same point value as cd, false otherwise
bool Card::operator== (const Card& cd) const
{
	if (cardFace == cd.cardFace)
		return true;
	else
		return false;
}
