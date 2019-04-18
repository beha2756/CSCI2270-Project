#include <string>
#include <queue>
#include <vector>
#include "player.hpp"

Player::Player()
{
	name = "Player";
	points = 0;
}

Player::~Player(){}

void Player::setName(std::string n)
{
	/*
	Purpose: Assigns a name to the player object
	Parameters: Name to be given to player
	Returns: None
	*/
	name = n;
}

void Player::printWinningCards()
{
	/*
	Purpose: Print the winning pairs of cards the player has won
	Parameters: None
	Returns:	None
	*/

}

void Player::addPoint()
{
	/*
	Purpose: Awards the player a single point
	Parameters: None
	Returns: None
	*/
	points++;
}

void Player::addWinningPair(std::string blackCard,std::string whiteCard)
{
	/*
	Purpose: Add a winning pair of cards to the player's winning cards queue
	Parameters: Strings of black card and whie card
	Returns: None
	*/
	winningPair newPair(blackCard,whiteCard);
	winningPairs.push(newPair);
}

std::string Player::getPlayerName()
{
	/*
	Purpose: Returns the name of the player
	Parameters: None
	Returns: Player's name
	*/
	return name;
}

int Player::getPlayerPoints()
{
	/*
	Purpose: Returns the number of points the player has
	Parameters: None
	Returns: Number of points the player has won
	*/
	return points;
}

void Player::addToHand(std::string card)
{
	/*
	Purpose: Add a card to the player's hand
	Parameters: String of card to be added
	Returns: None
	*/
	cards.push_back(card);
}

void Player::removeFromHand(int cardNum)
{
	/*
	Purpose: Removes a card from the player's hand
	Parameters: Card number to be removed
	Returns: None
	*/
	cards.erase(cards.begin()+cardNum-1);
}
