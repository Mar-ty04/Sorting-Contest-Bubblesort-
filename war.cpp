//Marisol Morales
//CECS 325 - 02
//Proj 2 - More War (vector)
//Due Date: 10/01/2024
//
//I certify that this program is my own original work. I didn not copy any part of this program from
//any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <time.h>
#include <string>

using namespace std;
class Card
{
	private:
		char rank;
		char suit;
	public:
		Card(char rk, char st) //constructor to create a card, setting the suit and rank
		{
			rank = rk;
			suit = st;
		}

		void print()  // display the card
		{
			if (rank == 'D'){
				cout << "10" << suit;
			}
			else {
				cout << rank << suit;
			}
		}

		int compare(Card CardTwo) // return 1 for win, 0 for tie, -1 for lose
		{
			if (rank == CardTwo.rank){
				return 0;
			} else if (rank == 'A'){
				return -1;
			} else if (CardTwo.rank == 'A'){
				return 1;
			} else if (rank == 'K'){
				return -1;
			} else if (rank > CardTwo.rank){
				return 1;
			} else {
				return -1;
			}
		}
};

class Deck
{
	private:
		vector<Card> pile;
	public:
		Deck() //constructor which creates a deck of 52 cards
		{
			char rank[] = {'A', '2', '3', '4','5','6', '7', '8', '9', 'D', 'J', 'Q', 'K'}; //D to represent ten (deca)
			char suit[] = {'C', 'S', 'D', 'H'};
			for(int s = 0; s < 4; s++){
				for(int r = 0; r < 13; r++){
					pile.push_back(Card(rank[r], suit[s]));
				}
			}
		}

		Card deal() // deal a card if u can - otherwise raise an exception 
		{
			if(pile.empty()){
				throw runtime_error("Error - Deck is empty.");
			}
			Card topCard = pile.front();
			pile.erase(pile.begin());
			return topCard;
			
		}

		void print() // show all of the cards in the deck
		{ 
			for(int i = 0; i < pile.size(); i++){
				pile[i].print();
				cout << ' ';

				if((i+1) % 13 == 0){
					cout << endl;
				}
			}
		}

		void shuffle() // shuffle the cards in the deck
		{
			srand(time(0));

			for(int i = 0; i < 52; i++){
				int index = rand() % 52;
				Card temp = pile[index];
				int index2 = rand() % 52;
				pile[index] =  pile[index2];
				pile[index2] = temp;
			}
		}

		bool isEmpty() //return true if deck is empty
		{
			return pile.empty();
		}
};

int main()
{
	string player1;
	cout << "Enter the name of the first player: ";
	cin >> player1;

	string player2;
	cout << "Enter the name of the second player: ";
	cin >> player2;
	
	int num_plays;
	cout << "How many games will they play? ";
	cin >> num_plays;
	cout << endl;

	Deck deck;
	cout << "Original Deck" << endl;
	deck.print();
	cout << endl;

	cout << "Shuffled Deck" << endl;
	deck.shuffle();
	deck.print();
	cout << endl;

	int player1win = 0;
	int player2win = 0;
	int roundWinner = 0;
	int gameTie = 0;

	try{
		for(int i = 0; i < num_plays; i++){
		
			Card player1Card = deck.deal();
			Card player2Card = deck.deal();

			cout << "Game" << ' ' << (i+1) << endl;
			cout << "----------" << endl;
			cout << endl;

		//	Card player1Card = deck.deal();
		//	Card player2Card = deck.deal();

			roundWinner = 0;

			cout << "        " << player1 << "==>" << ' ';
			player1Card.print();
			cout << endl;
			cout << "        " << player2 << "==>" << ' ';
			player2Card.print();
			cout << endl;

			roundWinner = player1Card.compare(player2Card);

			if(roundWinner == 1){
				player1win = player1win + 1;
				cout << player1 << "==>" << ' ' << "Winner" << endl;
			} else if(roundWinner == 0){
				gameTie = gameTie + 1;
				cout << "Tie Game" << endl;
			} else{
				player2win = player2win + 1;
				cout << player2 << "==>" << ' ' << "Winner" << endl;
			}

			cout << endl;
		}	
//		if (num_plays > 26) {
//			cout << "Error - Deck is empty." << endl;
//		}
	}
       	catch(const runtime_error& e){
		cout << e.what() << endl;
	}

	
	cout << "-------Final Stats-------" << endl;
	cout <<"       " << player1 << "  vs   " << player2 << endl;
	cout << "Wins" <<"    " << player1win << "         " <<player2win << endl;
	cout << "Losses" <<"  "<< player2win << "         " << player1win << endl;
	cout << "Ties" <<"    "<< gameTie << "          " << gameTie << endl;
	return 0;	

}
