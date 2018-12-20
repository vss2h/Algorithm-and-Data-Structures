// language: C++
// author: Vanessa Serao

#include "player.h"
#include "card.h"
#include "deck.h"
using std::cout;
using std::cin; 
using std::string;

// constructor - player's name defaults to "unknown" if not supplied
Player::Player(string nm)
{
	score = 0;
	name = nm;
	for (bool& i : hasPlayed)
		i = true;
}

// draw top card from the deck
void Player::drawCard(Deck & dk)
{
	if (dk.isEmpty())
		return;
	
	for (int i = 0; i < Max_Cards; i++)
	{
		if (hasPlayed[i])
		{
			hasPlayed[i] = false;
			hand[i] = dk.dealCard();
		}
	}
}

// add the point value of the card to the player's score
void Player::addScore(Card acard)
{
	score += acard.getPointValue();
}

// return the score the player has earned so far
int Player::getScore() const
{
	return score;
}

// return the name of the player
string Player::getName() const
{
	return name;
}

// Simulates player removing one card the first card from hand and playing it - returns the card
Card Player::playCard()
{
	for (int i = 0; i < Max_Cards; i++)
	{
		if (!hasPlayed[i])
		{
			hasPlayed[i] = true;
			return hand[i];
		}
	}
}

// return true if the player's hand is out of cards
bool Player::emptyHand() const
{
	return hasPlayed[Max_Cards];
}

// overload the << operator to display all cards in player's hand
ostream & operator<<(ostream & os, const Player & pl)
{
	for (int i = 0; i < 3; i++)
	{
		if(pl.hasPlayed[i])
			os << "_____" << "  ";
		else
			os << pl.hand[i] << "  ";
	}
	return os;
}
