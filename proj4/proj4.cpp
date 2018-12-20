// language: C++
// author: Vanessa Serao

#include <iostream>
#include <string>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "player.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{
	srand(1000);
	// cards instantiation
	Card play1;
	Card play2;
	//both player instantiation
	Player player1("Player 1");
	Player player2("Player 2");
	// desck instantiation
	Deck originaldeck;
	cout << "The original deck has the following cards " << endl << originaldeck << endl <<endl;
	originaldeck.Shuffle();
	cout << "the deck after shuffling <top of deck listed first>" << endl << originaldeck << endl;
	cout << endl;
	
	// Deal 3 cards to the players
	for (int i = 0; i < 3; i++)
	{
		player1.drawCard(originaldeck);
		player2.drawCard(originaldeck);
	}
	
	
	for(int i = 1; i <= 26; i++)
	{
		cout << "***************** Hand " << i <<" *****************" << endl;
		cout << "Player 1's hand: " << player1 << " with score " << player1.getScore() << endl;
		cout << "Player 2's hand: " << player2 << " with score " << player2.getScore() << endl;
		cout << endl;
		// make the players play their cards and print their play
		play1 = player1.playCard();
		cout << "Player 1 played card: " << play1 << " --- ";
		play2 = player2.playCard();
		cout << "Player 2 played card: " << play2 << endl << endl;

		if (play1.getPointValue() > play2.getPointValue())
		{
			player1.addScore(play2);
			player1.addScore(play1);
			cout << "Player 1 wins this hand\n";
		}
		else if (play1.getPointValue() == play2.getPointValue())
		{
			player1.addScore(play1);
			player2.addScore(play2);
			std::cout << "No player wins this hand, both players receive points for their cards" << "\n";
		}
		else {
			player2.addScore(play1);
			player2.addScore(play2);
			cout << "Player 2 wins this hand\n";
		}

		cout << "Player 1's hand: " << player1 << " with score " << player1.getScore() << endl;
		cout << "Player 2's hand: " << player2 << " with score " << player2.getScore() << endl;
		cout << endl;
		
		// Deal a card for each player
		player1.drawCard(originaldeck);
		player2.drawCard(originaldeck);
	}
	// Display players'  total scores
	if (player1.getScore() > player2.getScore())
		cout << "Player 1 wins with a score of " << player1.getScore() << endl;
	else if (player1.getScore() < player2.getScore())
		cout << "Player 2 wins with a score of " << player2.getScore() << endl;
	else 
		std::cout << "There is no winner to the game" << endl;
	
	system("pause");
	return 0;
}