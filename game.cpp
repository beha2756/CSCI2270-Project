/*
Purpose: Initializes the number of players in a game to numPlayers
Parameters: The number of players in the game
Return: None
*/
Game::Game(int numPlayers){
	this->numPlayers = numPlayers;
	turnNumber = 0;
}

/*
Purpose: Reads in a file and store the strings in the white card deck
Parameters: The name of the file to be read
Return: None
*/
void getWhiteDeck(std::string fileName){
	std::string card;
	std::ifstream whiteDeckStream(fileName);
	while(getline(whiteDeck,card)){
		whiteDeck.addToDeck(card);
	}
}

/*
Purpose: Reads in a file and store the strings in the black card deck
Parameters: The name of the file to be read
Return: None
*/
void getBlackDeck(std::string fileName){
	std::string card;
	std::ifstream blackDeckStream(fileName);
	while(getline(blackDeckStream,card)){
		blackDeck.addToDeck(card);
	}
}
//deals numCards to ever player
void dealHands(int numCards){
	for(int i = 0; i < numCards; i++){
		for(int j = 0; j < getNumPlayers(); j++){
			Player[j].addToHand(whiteDeck.dealCard());
		}
	}
}
//
//void startGame(int numPlayers);

void setMaxPoints(int numPoints){
	pointsToWin = numPoints;
}
//gets names of users and adds them to the player class
void addPlayers();

/*
Purpose: Checks to see if the game is over.
Parameters: None
Return: None
*/
bool isGameOver(){
	for(int i = 0; i < getNumPlayers(); i++){
		if(Players[i].getPlayerPoints() == getNumPointsToWin()){
			std::cout << "Game is over because " << Players[i].getName() << " has " << getNumPointsToWin() << " points" << std::endl;
			return true;
		}
	}
	if(blackCards.getSize() == 0){
		std::cout << "The black card deck is out of cards" << std::endl;
		return true;
	}
	if(whiteCards.getSize()) < getNumPlayers()){
		std::cout << "There are not enough white cards for another hand" << std::endl;
		return true;
	}
}


int getNumPlayers(){
	return numPlayers;
}

int getNumPointsToWin(){
	return pointsToWin;
}

void incrementTurnNumber(){
	turnNumber++;
}

void getTurnNumber(){
	return turnNumber;
}

void playTurn(){
	int cardCzar = getTurnNumber() % getNumPlayers();
	std::string chosenCard;
	int chosenCardNum;
	std::vector <std::string> playedCards;
	std::string blackCard = blackCards.dealCard();
	std::cout << Players[cardCzar].getPlayerName() << " is the card czar. They will not play a card this turn" << std::endl;
	for(int i = 0; i < getNumPlayers(); i++){

		if(cardCzar != i){
			std::cout << "The black card for this turn is " << blackCard << std::endl;
			Players[i].printCards(//); //make sure name of func is printHand
			std::cout << "Enter the number of the card you would like to play with 1 being the first card" << std::endl;
			std::cin >> chosenCardnum;

			while(chosenCardNum >= 7 || chosenCardNum < 1){
				std::cout << "Enter a new number for a card you would like to play, your last choice was invalid" << std::endl;
				Players[i].printCards(//); //make sure name of func is printHand
				std::cin >> chosenCardNum;
				Players[i].removeFromHand(chosenCardNum);
			}

			playedCards.push_back()
		}
	}
	std::cout << "Pass the computer to " << Players[cardCzar].getPlayerName() << "." << std::endl;
	std::cout << "Enter the number of the winning card with 0 being the first card" << std::endl;

}
