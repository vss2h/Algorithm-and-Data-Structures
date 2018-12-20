// language: C++
// author: Vanessa Serao


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "card.h"
#include "deck.h"
using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::endl;


// constructor
Deck::Deck()
{
	// initialize topCard 
	topCard = 0;

	//fill the Deck array with cards
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			theDeck[i*13+j-1] = Card::Card(j, static_cast<suit>(i));
		}
	}
		
}

// Remove the top card from the deck and return it.
Card Deck::dealCard()
{
	if (!isEmpty())
	{
		return theDeck[topCard++];
	}
}

// Shuffle the cards in the deck
void Deck::Shuffle()
{
	int rnd;		// stores our random number
	Card shuffle;	// used to swap the random numbers

	for (int i = 0; i < numCards; i++) 
	{
		rnd = (time(0) + rand()) % numCards;
		shuffle = theDeck[i];
		theDeck[i] = theDeck[rnd];
		theDeck[rnd] = shuffle;
	} 
	
}

// return true if there are no more cards in the deck, false otherwise
bool Deck::isEmpty()
{
	if (topCard >= 52)
		return true;
	else
		return false;
}

//overload << operator to display the deck
ostream & operator<<(ostream & os, const Deck & dk)
{
	for (int i = 51; i >= dk.topCard; i--)
	{
		os << dk.theDeck[i] << "  ";
			if (i == 7 || i == 16 || i == 25 || i == 34 || i == 43)
				os << endl;
	}
	return os ;
}
