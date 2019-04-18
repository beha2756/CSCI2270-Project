//Default constructor, initialize name and points;
Player()
{
	name = "Player";
	points = 0;
}

//Default destructor, not used
~Player(){}

//set player name
void setName(std::string n)
{
	name = n;
}

//print vector of all winning card pairs
printWinningCards()
{

}

//incriment player points by 1
void addPoint()
{
	points++;
}

//add winning pair to array
void addWinningPair(std::string blackCard,std::string whiteCard)
{
	winningPair newPair(blackCard,whiteCard);
	winningPairs.push(newPair);
}

//return player name
std::string getPlayerName()
{
	return name;
}

//return player points
std::string getPlayerPoints()
{
	return points;
}

//add card string to player'Player
void addToHand(std::string card)
{

}

//remove card string from player's hand
void removeFromHand(std::string card)
{

}
