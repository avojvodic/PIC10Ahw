//  
// PIC 10A Homework 5
//  May 15, 2017
//
// Aleksandra Vojvodic
// Student ID: 904578899
//

#include <iostream>
#include <string>
#include "stdio.h"
#include "stdlib.h"
#include <ctime>

using namespace std;

//total: the total number of points in player's hand
int draw_card(string &card, int total){

	int rank;
	int suit;

	rank = (rand() % 13) + 1; //randomize rank
	suit = (rand() % 4) + 1; //randomize suit

	// assign rank to card number

	card = "";
	if (rank == 1) card = "Ace";
	else if (rank == 2) card = "Two";
	else if (rank == 3) card = "Three";
	else if (rank == 4) card = "Four";
	else if (rank == 5) card = "Five";
	else if (rank == 6) card = "Six";
	else if (rank == 7) card = "Seven";
	else if (rank == 8) card = "Eight";
	else if (rank == 9) card = "Nine";
	else if (rank == 10) card = "Ten";
	else if (rank == 11) card = "Jack";
	else if (rank == 12) card = "Queen";
	else if (rank == 13) card = "King";

	// assign suit number to suit of cards

	if (suit == 1) card += " of Spades";
	else if (suit == 2) card += " of Clubs";
	else if (suit == 3) card += " of Diamonds";
	else if (suit == 4) card += " of Hearts";


	int added_value; //figure out added_value

	if (rank == 1)
	{
		if (total <= 10) added_value = 11;
		else added_value = 1;
	}
	else if ((rank >= 2) && (rank <= 10))
	{
		added_value = rank;
	}
	else
	{
		added_value = 10;
	}

	return added_value;
}


int main()
{
	srand(time(NULL)); //randomize cards

	int amount = 100;  //amount of money
	cout << "You have $100. ";

	while ((amount > 0) && (amount < 1000))
	{
		int bet;
		cout << "Enter bet: ";
		cin >> bet;

		//check if bet is valid
		//if not, ask again

		while (bet > amount)
		{
			cout << "You only have $" << amount << " to bet. Enter bet: ";
			cin >> bet;
		}

		// PLAYER'S HAND

		int total = 0;
		string card, card1, card2;
		string more = "y";

		total += draw_card(card1, total);
		total += draw_card(card2, total);

		//print card1 and card2;
		cout << "\n" << "Your cards are: " << "\n" << "  " << card1 << "\n" << "  " << card2 << "\n";

		//print the total
		cout << "Your total is " << total << ". Do you want another card (y/n)? ";

		cin >> more;

		while ((total < 21) && (more == "y"))
		{
			total = total + draw_card(card, total);

			cout << "\n" << "You draw a:" << "\n" << "  " << card << "\n" << "Your total is " << total << ". ";

			// ask if the user wants another card
			if (total < 21)
			{
				cout << "Do you want another card (y/n)? ";
				cin >> more;
			}

		}

		// check if the player went bust
		if (total > 21)
		{
			cout << "You busted!" << "\n";
		}

		// if not then move on to Dealer's turn
		// DEALER'S HAND

		int d_total = 0;
		string d_card, d_card1, d_card2;

		d_total += draw_card(d_card1, d_total);
		d_total += draw_card(d_card2, d_total);

		// print card1 and card2;

		cout << "\n" << "The dealer's cards are: " << "\n" << "  " << d_card1 << "\n" << "  " << d_card2 << "\n";

		// print the total
		cout << "The dealer's total is " << d_total << "." << "\n" << "\n";


		while (d_total <= 16)
		{
			d_total += draw_card(d_card, d_total);

			// give dealer another card
			cout << "The dealer draws a card. " << "\n";
			cout << "  " << d_card << "\n";

			cout << "The dealer's total is " << d_total << "." << "\n" << "\n";
		}


		if ((total == d_total) && (total <= 21))
		{
			// tie game
			cout << "It's a draw! ";
			cout << "You get back your $" << bet << "." << "\n" << "\n";
			cout << "You have $" << amount << ". ";
		}
		else if ((total > d_total && total <= 21) || (total <= 21 && d_total > 21))
		{
			// player wins
			amount += bet;
			cout << "Yay! You win $" << bet << "!" << "\n" << "\n";
			cout << "You have $" << amount << ". ";
		}
		else if (total > 21)
		{
			// dealer wins because of bust
			amount -= bet;
			cout << "Too bad! You lose $" << bet << "." << "\n" << "\n";
			cout << "You have $" << amount << ". ";

		}
		else if (total < d_total && d_total <= 21)
		{
			// dealer wins by comparison
			amount -= bet;
			cout << "Too bad. You lose $" << bet << "." << "\n" << "\n";
			cout << "You have $" << amount << ". ";
		}

	}

	if (amount == 0)
	{
		cout << "Too bad! You lose! Game over. ";
	}
	else
	{
		cout << "You win! Game over. ";
	}

	system("pause");
	return 0;
}
