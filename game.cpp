#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "game.hpp"

/*
Purpose: Print endlines to the console
Parameters: number of endlines to print
Return: None
*/
void printEndlines(int n)
{
	for(int i=0; i<n; i++)
	{
		std::cout << std::endl;
	}
}

/*
Purpose: Takes in a vector of strings, where each string represents a card, and prints them
Parameters: Vector of strings (cards), number of cards to print, and whether or not to number the cards
Returns: None
*/
void printCards(std::vector<std::string> inputVector, bool includeNumbers)
{

	int numCards = inputVector.size();
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
Purpose: Prints a single black card to the console
Parameters: String of text to be on the card
Returns: None
*/
void printBlackCard(std::string blackCardText)
{
	std::vector<std::string> vect;
	vect.push_back(blackCardText);
	printCards(vect,false);
}
/*
Purpose: Print out all player information onto the screen
Parameters: int representing card czar, int for which players turn, vector of players classes, and  points to win
Return: None
*/
void printPlayInfo(int cardCzar, int playing, std::vector<Player> playerVect, int maxWinPoints)
{
	int playerNum = playerVect.size();
	//print top of table
	for(int i= 0; i<playerNum+2; i++)
	{
		if(i==0)
			std::cout << "     ";
		std::cout << "________________";
	}
	std::cout << std::endl;

	//print player/czar flag
	for(int i=0; i<playerNum+1;i++)
	{

		if(i == 0)
			std::cout << "     |";
		if(i==cardCzar && playing == -1)
			std::cout << "   [CHOOSING]  |";
		else if(i == cardCzar)
			std::cout << "     [CZAR]    |";
		else if(i == playing)
			std::cout << "   [PLAYING]   |";
		else if(i == playerNum)
			std::cout << "|############################||";
		else
			std::cout << "               |";
	}
	std::cout << std::endl;

	//print table divider
	for(int i=0; i<playerNum+1; i++)
	{
		if(i < playerNum)
		{
			if(i==0)
				std::cout << "     |";
			std::cout << "===============|";
		}
		else if (i == playerNum)
		{
			std::cout << "|#                          #||";
		}
	}
	std::cout << std::endl;

	//print player names
	for(int i=0; i<playerNum+1;i++)
	{
		if(i < playerNum)
		{
			if(i == 0)
				std::cout << "     ";
			std::cout  << "| "<< playerVect[i].getPlayerName();
			for(int j=playerVect[i].getPlayerName().size(); j<14; j++)
			{
				std::cout << " ";
			}
			if(i == playerNum-1)
			{
				std::cout << "|";
			}
		}
		else if(i == playerNum)
		{
			std::cout << "|#    NUM POINTS TO WIN:    #||";
		}

	}
	std::cout << std::endl;

	//print table divider
	for(int i=0; i<playerNum+1; i++)
	{
		if(i < playerNum)
		{
			if(i==0)
				std::cout << "     |";
			std::cout << "===============|";
		}
		else if (i == playerNum)
		{
			// std::cout << "|# NUMBER OF POINTS TO WIN: #||";
			std::cout << "|#            " << maxWinPoints;
			if(maxWinPoints < 10)
				std::cout << " ";
			std::cout << "            #||";
		}
	}
	std::cout << std::endl;

	//print scores
	for(int i=0; i<playerNum+1;i++)
	{
		if(i<playerNum)
		{
			if(i == 0)
				std::cout << "     ";
			std::cout << "| Score: " << playerVect[i].getPlayerPoints();
			if(playerVect[i].getPlayerPoints() < 10)
				std::cout << " ";
			for(int j=9; j<14; j++)
			{
				std::cout << " ";
			}
			if(i == playerNum-1)
			{
				std::cout << "|";
			}
		}
		else if(i == playerNum)
		{
			std::cout << "|#                          #||";
		}

	}
	std::cout << std::endl;
	//print table divider
	for(int i=0; i<playerNum+1; i++)
	{
		if(i < playerNum)
		{
			if(i==0)
				std::cout << "     |";
			std::cout << "===============|";
		}
		else if (i == playerNum)
		{
			std::cout << "|############################||";
		}
	}
	std::cout << std::endl << std::endl;
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

	getWhiteDeck("whiteCards.txt");
	getBlackDeck("blackCards.txt");
	whiteCards.shuffleDeck();
	blackCards.shuffleDeck();
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
			for(int j = 0; j < numPlayers; j++)
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
	return false;
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

void Game::addPlayers()
{
	for(int i=0; i<numPlayers; i++)
	{
		Player newPlayer;
		std::string playerName;
		std::cout << "          Enter name for Player " << i+1 << ": ";
		getline(std::cin,playerName);

		newPlayer.setName(playerName);
		Players.push_back(newPlayer);
	}
}

/*
Purpose: Simulates one turn of the game
Parameters: None
Return: None
*/
void Game::playTurn()
{
	//gets the index of the card czar
	std::string temp;
	int cardCzar = getTurnNumber() % getNumPlayers();
	std::string chosenCard;
	int chosenCardNum,winningCard;

	//vector of the index of each player who plays a card
	std::vector <int> playerNum;

	//vector of strings with each index being the string of the card that player played
	std::vector <std::string> playedCards;

	//gets the string of the black card for the turn
	std::string blackCard = blackCards.dealCard();



	//runs through all the players
	for(int i = 0; i < getNumPlayers(); i++){

		//skips the card czar
		if(cardCzar != i){

			//adds the index of the player to the playerNum vector
			playerNum.push_back(i);
			//Print player info
			printEndlines(20);
			printPlayInfo(cardCzar,i,Players,pointsToWin);
			//print the black card for the round
			printBlackCard(blackCard);


			printEndlines(10);
			std::cout << "          " << Players[cardCzar].getPlayerName() << " is the card czar this round" << std::endl;
			std::cout << std::endl;
			std::cout << "          It is "<< Players[i].getPlayerName() << "'s turn, give them the laptop (press ENTER to continue)" << std::endl;
			getline(std::cin,temp);
			//Prints the players cards
			printCards(Players[i].getPlayerCards(), true);
			std::cout << std::endl;
			std::cout << "          Enter the number of the card you would like to play (1-7): ";
			getline(std::cin,temp);
			chosenCardNum = stoi(temp);

			//exit condition
			if(chosenCardNum == 9)
			{
				// return true;
			}
			//Checks for invalid NUMBER inputs
			while(chosenCardNum > 7 || chosenCardNum < 1)
			{
				//gets a new number for a card to be played
				std::cout << "          Error: Choice must be integer between 1 and 7" << std::endl;
				std::cout << "          Enter the number of the card you would like to play (1-7): ";
				// printCards(Players[i].getPlayerCards(), true);
				getline(std::cin,temp);
				chosenCardNum = stoi(temp);
			}
			//adds the chosen card to the played cards vector and also removes that card from the hand
			playedCards.push_back(Players[i].playCard(chosenCardNum-1));
		}
		// return false;
	}


	printEndlines(20);
	printPlayInfo(cardCzar,-1,Players,pointsToWin);
	printBlackCard(blackCard);
	printEndlines(10);
	std::cout << Players[cardCzar].getPlayerName() << " will choose the winning card, give them the laptop" << std::endl;
	getline(std::cin, temp);
	//prints the cards that have been played
	printCards(playedCards, true);
	std::cout << std::endl;

	//gets the number of the card the card czar chose
	std::cout << "          Enter the number of the winning card (1-" << numPlayers-1 <<"): ";
	getline(std::cin,temp);
	winningCard = stoi(temp);

	//prints out the name of the winning player
	std::cout << Players[playerNum[winningCard - 1]].getPlayerName() << " won this round" << std::endl;
	//awards the player a points
	Players[playerNum[winningCard - 1]].addPoint();

	//adds the winning pair to the winning players winning pair struct
	Players[playerNum[winningCard - 1]].addWinningPair(blackCard, playedCards[winningCard - 1]);

	incrementTurnNumber();

	//deals new cards
	dealHands(1, cardCzar);
}
