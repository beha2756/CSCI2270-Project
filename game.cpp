#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "game.hpp"

void printCards(std::vector<std::string> inputVector, int numCards, bool includeNumbers)
{
	/*
	Purpose: Takes in a vector of strings, where each string represents a card, and prints them
	Parameters: Vector of strings (cards), number of cards to print, and whether or not to number the cards
	Returns: None
	*/
	std::string temp1;
	std::vector<int> currentLineLength(numCards);
	int maxLineLength = 15;
	int cardHeight = 9;

	//create an array of string vectors
	std::vector<std::vector<std::string>> cardVect(numCards);

	//loops for every card passed into function
	for(int i=0; i<numCards; i++)
	{
		//open stream for card string stored in input card std::vector<int> v;
		std::stringstream cardStream(inputVector[i]);

		//Push each word from the string into the vector
		while(getline(cardStream,temp1,' '))
		{
			cardVect[i].push_back(temp1);
		}

	}
	// okay now we have an array of vectors, where each vector is a vector of
	// the words from the string

	//loops for each line of the card;
	std::vector<int> index(7);

	//print top of card
	for(int i=0; i<numCards; i++)
	{
		std::cout << "     ___________________";
	}
	std::cout << std::endl;
	for(int i=0; i<numCards; i++)
	{
		std::cout << "     |                 |";
	}
	std::cout << std::endl;

	//print content of card
	for(int i=0; i<cardHeight; i++)
	{
		for(int j=0; j<numCards;j++)
		{
			currentLineLength[j] = 0;
		}
		//loops for each card
		for(int j=0; j<numCards; j++)
		{
			std::cout << "     | ";
			while(currentLineLength[j] + cardVect[j][index[j]].size() + 1 <= maxLineLength)
			{
				// breaks if no more words in vector
				if(index[j] >= cardVect[j].size()) break;

				std::cout << cardVect[j][index[j]] << " ";

				//increment line length by word length + 1 (the space)
				currentLineLength[j] += cardVect[j][index[j]].size() + 1;
				index[j]++;
			}
			//fill the rest of the line with spaces
			for(int k=currentLineLength[j]; k<maxLineLength; k++)
			{
				std::cout << " ";
			}
			std::cout << " |";
		}
		std::cout << std::endl;
	}
	//print number on card

	for(int i=0; i<numCards; i++)
	{

		if(includeNumbers)
			std::cout << "     |------=(" << i+1 << ")=------|";
		else
			std::cout << "     |                 |";
	}
	std::cout << std::endl;
	//print bottom of card
	for(int i=0; i<numCards; i++)
	{
		std::cout << "     |_________________|";
	}
	std::cout << std::endl;

}

/*
Purpose: Initializes the number of players in a game to numPlayers and pointsToWin to maxPoints
Parameters: The number of players in the game
Return: None
*/
Game::Game(int numPlayers, int maxPoints)
{
	this->numPlayers = numPlayers;
	pointsToWin = maxPoints;
	turnNumber = 0;
}

/*
Purpose: Reads in a file and store the strings in the white card deck
Parameters: The name of the file to be read
Return: None
*/
void Game::getWhiteDeck(std::string fileName)
{
	std::string card;
	std::ifstream whiteCardsStream(fileName);
	while(getline(whiteCardsStream,card)){
		whiteCards.addToDeck(card);
	}
}

/*
Purpose: Reads in a file and store the strings in the black card deck
Parameters: The name of the file to be read
Return: None
*/
void Game::getBlackDeck(std::string fileName)
{
	std::string card;
	std::ifstream blackCardsStream(fileName);
	while(getline(blackCardsStream,card)){
		blackCards.addToDeck(card);
	}
}

/*
Purpose: Reads white cards to each player
Parameters: The number of cards to be dealt
Return: None
*/
void Game::dealHands(int numCards, int cardCzar)
{
	if(cardCzar == -1)
	{
		for(int i = 0; i < numCards; i++)
		{
			for(int j = 0; j < getNumPlayers(); j++)
			{
				Players[j].addToHand(whiteCards.dealCard());
			}
		}
	}
	else{
		for(int i = 0; i < numCards; i++)
		{
			for(int j = 0; j < getNumPlayers(); j++)
			{
				if(cardCzar != j)
				{
					Players[j].addToHand(whiteCards.dealCard());
				}
			}
		}
	}
}

//gets names of users and adds them to the player class


/*
Purpose: Checks to see if the game is over.
Parameters: None
Return: None
*/
bool Game::isGameOver()
{
	for(int i = 0; i < getNumPlayers(); i++)
	{
		if(Players[i].getPlayerPoints() == getNumPointsToWin())
		{
			std::cout << "Game is over because " << Players[i].getPlayerName() << " has " << getNumPointsToWin() << " points" << std::endl;
			return true;
		}
	}
	if(blackCards.getDeckSize() == 0)
	{
		std::cout << "The black card deck is out of cards" << std::endl;
		return true;
	}
	if(whiteCards.getDeckSize() < getNumPlayers())
	{
		std::cout << "There are not enough white cards for another hand" << std::endl;
		return true;
	}
}

/*
Purpose: Returns the number of players
Parameters: None
Return: Number of players
*/
int Game::getNumPlayers()
{
	return numPlayers;
}

/*
Purpose: Returns the number of points to win
Parameters: None
Return: Number of points to win
*/
int Game::getNumPointsToWin()
{
	return pointsToWin;
}

/*
Purpose: increments the turn counter
Parameters: None
Return: None
*/
void Game::incrementTurnNumber()
{
	turnNumber++;
}

/*
Purpose: Returns the turn number
Parameters: None
Return: Turn number
*/
int Game::getTurnNumber()
{
	return turnNumber;
}

/*
Purpose: Simulates one turn of the game
Parameters: None
Return: None
*/
void Game::playTurn()
{
	//gets the index of the card czar
	int cardCzar = getTurnNumber() % getNumPlayers();

	std::string chosenCard;
	int chosenCardNum;
	std::string winningCard;

	//vector of the index of each player who plays a card
	std::vector <int> playerNum;

	//vector of strings with each index being the string of the card that player played
	std::vector <std::string> playedCards;

	//gets the string of the black card for the turn
	std::string blackCard = blackCards.dealCard();

	std::cout << Players[cardCzar].getPlayerName() << " is the card czar. They will not play a card this turn" << std::endl;

	//runs through all the players
	for(int i = 0; i < getNumPlayers(); i++){

		//skips the card czar
		if(cardCzar != i){

			//adds the index of the player to the playerNum vector
			playerNum.push_back(i);

			std::cout << "The black card for this turn is " << blackCard << std::endl;

			//Prints the players cards
			printCards(Players[i].getPlayerCards(), true);

			std::cout << "Enter the number of the card you would like to play " << std::endl;
			std::cin >> chosenCardNum;

			//Checks for invalid NUMBER inputs
			while(chosenCardNum > 7 || chosenCardNum <= 0)
			{
				//gets a new number for a card to be played
				std::cout << "Enter a new number for a card you would like to play, your last choice was invalid" << std::endl;
				printCards(Players[i].getPlayerCards(), true);
				std::cin >> chosenCardNum;
			}
			//adds the chosen card to the played cards vector and also removes that card from the hand
			playedCards.push_back(Players[i].playCard(chosenCardNum));
		}
	}

	std::cout << "Pass the computer to " << Players[cardCzar].getPlayerName() << "." << std::endl;

	//prints the cards that have been played
	printCards(playedCards, true);

	//gets the number of the card the card czar chose
	std::cout << "Enter the number of the winning card with 1 being the first card" << std::endl;
	std::cin >> winningCard;

	//prints out the name of the winning player
	std::cout << Players[playerNum[stoi(winningCard) - 1]].getPlayerName() << "won this round" << std::endl;

	//adds the winning pair to the winning players winning pair struct
	Player[playerNum[stoi(winningCard) - 1]].winningPair(blackCard, playedCards[stoi(winningCard) - 1]);

	incrementTurnNumber();

	//deals new cards
	dealHands(1, cardCzar);
}




int main(){

}
