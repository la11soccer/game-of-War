#include <iostream>
#include "Card.h"
#include <queue>
#include <vector>
using namespace std;

void Shuffle(queue <Card>& tempDeck)//pass in by reference
{
	//create vector and add the cards from the queue into it
	vector <Card> toShuffle;
	int size = tempDeck.size();
	for (int i = 0; i < 26; i++)
	{
		toShuffle.push_back(tempDeck.front());
		tempDeck.pop();
	}
	//cout << toShuffle.size();

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			//set cards to temporary values to be swapped
			Card tempI = toShuffle.at(i);
			Card tempJ = toShuffle.at(j);

			//if the below condition is true, swap I and J Cards
			if (rand() % 2 == 0)
			{
				Card tempTemp = tempI;
				toShuffle.at(i) = tempJ;
				toShuffle.at(j) = tempTemp;
				

			}

		}
	}
	//cout << toShuffle.size();
	for (int i = 0; i < toShuffle.size(); i++)
	{
		tempDeck.push(toShuffle.at(i));
	}
}

int main()
{
	//variable to hold to seed entered by user
	int chosenSeed;
	int Play1TieCard1, Play2TieCard1, Play1TieCard2, Play2TieCard2;

	//create 2 card decks with queues
	queue <Card> deck1;
	queue <Card> deck2;
	vector<Card> warCards;
	bool war = false;

	//add cards to deck 1


	for (int i = 0; i <	13; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			deck1.push(Card(i));
			//deck2.push(Card(i));
		}
	}
	
	for (int i = 0; i < 13; i++)
	{
		//deck1.push(Card(i));
		//deck1.push(Card(i));
		deck2.push(Card(i));
		deck2.push(Card(i));
		
	}
	
	
	cout << "Welcome to WAR!\nWhat seed would you like?\n";
	cin >> chosenSeed;
	srand(chosenSeed);

	Shuffle(deck1);
	Shuffle(deck2);

	//tester function to print
	/*
	
	for (int i = 0; i < 26; i++)
	{
		cout << deck1.front().getValue();
		deck1.pop();
	}
	cout << "\n";

	for (int i = 0; i < deck2.size(); i++)
	{
		cout << deck2.front().getValue();
		deck2.pop();
	}*/

	//while both decks are not empty
	
	while (!deck1.empty() && !deck2.empty())
	{
		//get the two cards to be played from each deck
		Card play1 = deck1.front();
		Card play2 = deck2.front();
		 
		cout << play1.getValue() << " vs " << play2.getValue() << "\n";
		deck1.pop();
		deck2.pop();

		//if player 1 has the larger card, add both cards to his deck
		if (play1.getValue() > play2.getValue())
		{
			deck1.push(play1);
			deck1.push(play2);
		}
		//else if player 2 has the larger card, add both cards to his deck
		else if (play1.getValue() < play2.getValue())
		{
			deck2.push(play1);
			deck2.push(play2);
		}
		//else if players cards are equal got to war
		else //if(play1.getValue() == play2.getValue())
		{

			cout << "WAR!\n";
			war = true;
			warCards.push_back(play1);
			warCards.push_back(play2);


			
			while (war == true)
			{
				//create vector to hold cards in
				
				//add the two cards just ppplayed to the vector
				

				//if both players have enought cards, put 2 face down and a third face up
				if (deck1.size() > 2 && deck2.size() > 2)
				{
					//set the plays to the two new cards
					play1 = deck1.front();
					play2 = deck2.front();
					//add plays to the vector and print them out
					warCards.push_back(play1);
					warCards.push_back(play2);
					//print
					cout << "facedown player1: " << play1.getValue() << "\n";
					//pop deck 1 and get the next card
					deck1.pop();
					play1 = deck1.front();
					//add card to the vector
					warCards.push_back(play1);
					//print
					cout << "facedown player1: " << play1.getValue() << "\n";
					//popdeck and get the next card that will actuallt be played for player 1
					deck1.pop();
					play1 = deck1.front();
					//add card to the vector
					warCards.push_back(play1);

					cout << "facedown player2: " << play2.getValue() << "\n";
					//pop deck2 and get the next card
					deck2.pop();
					play2 = deck2.front();
					//add card to the vector
					warCards.push_back(play2);
					//print
					cout << "facedown player2: " << play2.getValue() << "\n";
					//popdeck ad get the next card taht will actually be played fro player 2
					deck2.pop();
					play2 = deck2.front();
					warCards.push_back(play2);
					deck1.pop();
					deck2.pop();

					//print out the vs cards
					cout << "-- " << play1.getValue() << " vs " << play2.getValue() << " --\n";

					//if player 1 has the larger card, add vector of cards to his deck
					if (play1.getValue() > play2.getValue())
					{
						for (int i = 0; i < warCards.size(); i++)
						{
							deck1.push(warCards.at(i));
						}
						//clear the vector
						warCards.clear();
						war = false;
					}
					//if player 2 has the larger card, add vector of cards to his deck
					else if (play1.getValue() < play2.getValue())
					{
						for (int i = 0; i < warCards.size(); i++)
						{
							deck2.push(warCards.at(i));
						}
						//clear the vector
						warCards.clear();
						war = false;
					}
					else
					{
						war = true;
					}

				}
				else if (deck1.size() > 2 && deck2.size() == 2)
				{
					//war = false;
					play1 = deck1.front();
					play2 = deck2.front();
					//add the cards to the vector
					warCards.push_back(play1);
					warCards.push_back(play2);
					cout << "facedown player1: " << play1.getValue() << "\n";
					//pop deck 1 and get the next card
					deck1.pop();
					play1 = deck1.front();
					warCards.push_back(play1);
					cout << "facedown player1: " << play1.getValue() << "\n";
					deck1.pop();
					play1 = deck1.front();
					warCards.push_back(play1);
					cout << "facedown player2: " << play2.getValue() << "\n";
					deck2.pop();
					play2 = deck2.front();
					warCards.push_back(play2);
					//cout << "facedown player2: " << play2.getValue() << "\n";
					//print out the cards, player2 ran out of cards
					cout << play1.getValue() << " vs " << play2.getValue() << "\n";
					deck1.pop();
					deck2.pop();
					if (play1.getValue() > play2.getValue())
					{
						for (int i = 0; i < warCards.size(); i++)
						{
							deck1.push(warCards.at(i));
						}
						//clear the vector
						warCards.clear();
						war = false;
					}
					//if player 2 has the larger card, add vector of cards to his deck
					else if (play1.getValue() < play2.getValue())
					{
						for (int i = 0; i < warCards.size(); i++)
						{
							deck2.push(warCards.at(i));
						}
						//clear the vector
						warCards.clear();
						war = false;
					}
					else
					{
						war = true;
					}



				}
				else if (deck1.size() == 2 && deck2.size() > 2)
				{
					//war = false;
					play1 = deck1.front();
					play2 = deck2.front();
					warCards.push_back(play1);
					warCards.push_back(play2);

					cout << "facedown player1: " << play1.getValue() << "\n";
					deck1.pop();
					play1 = deck1.front();

					cout << "facedown player2: " << play2.getValue() << "\n";
					deck2.pop();
					play2 = deck2.front();
					warCards.push_back(play2);
					cout << "facedown player2: " << play2.getValue() << "\n";
					deck2.pop();
					play2 = deck2.front();
					cout << play1.getValue() << " vs " << play2.getValue() << "\n";
					deck1.pop();
					deck2.pop();
					if (play1.getValue() > play2.getValue())
					{
						for (int i = 0; i < warCards.size(); i++)
						{
							deck1.push(warCards.at(i));
						}
						//clear the vector
						warCards.clear();
						war = false;
					}
					//if player 2 has the larger card, add vector of cards to his deck
					else if (play1.getValue() < play2.getValue())
					{
						for (int i = 0; i < warCards.size(); i++)
						{
							deck2.push(warCards.at(i));
						}
						//clear the vector
						warCards.clear();
						war = false;
					}
					else
					{
						war = true;
					}


				}
				else
				{

				}/*
				else if (deck1.size() > 2 && deck2.size() == 1)
				{
					war = false;
					play1 = deck1.front();
					play2 = deck2.front();
					cout << "facedown player1: " << play1.getValue() << "\n";
					//pop deck 1 and get the next card
					deck1.pop();
					play1 = deck1.front();
					cout << "facedown player1: " << play1.getValue() << "\n";
					deck1.pop();

				}
				else if (deck1.size() == 1 && deck2.size() > 2)
				{
					war = false;
					play1 = deck1.front();
					play2 = deck2.front();
					cout << "facedown player1: " << play1.getValue() << "\n";
					cout << "facedown player2: " << play2.getValue() << "\n";
					deck2.pop();
					play2 = deck2.front();
					cout << "facedown player2: " << play2.getValue() << "\nPlayer 2 Wins!!";
				}
				else
				{
					war = false;
					if (deck1.empty())
					{
						cout << "Player 2 wins!!";
					}
					if (deck2.empty())
					{
						cout << "Player 1 wins!!";
					}
				}*/
			}
			//cout << deck1.size() << "\n";
			//cout << deck2.size() << "\n";
			
		}
		if (deck1.empty())
		{
			cout << "Player 2 wins!!";
		}
		if (deck2.empty())
		{
			cout << "Player 1 wins!!";
		}
		
	}
}

