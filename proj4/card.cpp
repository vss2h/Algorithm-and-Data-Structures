// language: C++
// author: Vanessa Serao

#include "card.h"
#include <iostream>
#include <cassert>
#include <string>
using std::cout;
using std::cin;
using std::string;


//constructor that takes a card's face (represented an integer) and suit
// card face example: Ace=0, 2=1, 3=2, ... Q=11, K=12 or some other ordering

Card::Card()
{}

Card::Card(int face, suit st)
{
	cardSuit = st;
	cardFace = face;
	
	if (face > 1 && face < 10) // numbers
		pointValue = face;
	else if (face >= 10 && face < 15) // K, Q and J
		pointValue = 10;
	else                          // Ace
		pointValue = 15;
	
}

// overload the << operator to display the card
std::ostream& operator << (ostream& os, const Card& cd)
{
	char suit = cd.cardSuit;	//holds the card's suit

	// print suit symbol
	if (suit == hearts)
		suit= 'H';
	else if (suit == diamonds)
		suit= 'D';
	else if (suit == clubs)
		suit = 'C';
	else if (suit == spades)
		suit= 'S';
	
	// prints the cardFace,cardSuit and card's pointValue
	if (cd.cardFace > 1 && cd.cardFace <= 10)
		os << cd.cardFace << suit << "[" << cd.pointValue << "]" << " ";
	else if (cd.cardFace == 11)
		os << "J" << suit << "[" << cd.pointValue << "]" << " ";
	else if (cd.cardFace == 12) 
		os << "Q" << suit << "[" << cd.pointValue << "]" << " ";
	else if (cd.cardFace == 13) 
		os << "K" << suit << "[" << cd.pointValue << "]" << " ";
	else
		os << "A" << suit << "[" << cd.pointValue << "]" << " ";
	return os;
}

// compare and return true if *this has a lesser point value than cd, false otherwise
bool Card:: operator < (const Card& cd) const
{
	if (this < &cd)
		return true;
	else
		return false;
}

// compare and return true if *this has a larger point value than cd, false otherwise
bool Card:: operator > (const Card& cd) const
{
	if (this > &cd)
		return true;
	else
		return false;
}

// compare and return true if *this has the same point value as cd, false otherwise
bool Card::operator== (const Card& cd) const
{
	if (this == &cd)
		return true;
	else
		return false;
}

// return the point value of the card: Ace: 15, Faces: 10, Numbers: the number
int Card::getPointValue() const
{
	return pointValue;
}




