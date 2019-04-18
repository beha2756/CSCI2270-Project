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
	int chosenCardNum;
	int
	std::cout << Players[cardCzar].getPlayerName() << " is the card czar. They will not play a card this turn" << std::endl;
	for(int i = 0; i < getNumPlayers(); i++){
		if(cardCzar != i){
			std::cout << "The black card for this turn is " << blackCards.dealCard() << std::endl;
			Players[i].printHand(); //make sure name of func is printHand
			std::cout << "Enter the number of the card with 0 being the first card and 6 being the last" << std::endl;
			std::cin >> chosenCardNum;
		}
	}
}

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
