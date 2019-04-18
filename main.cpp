#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include "player.hpp"

int main()
{
	/*
	Purpose:
	Parameters:
	Returns:
	*/
	Player myPlayer;

	myPlayer.setName("Lil Pump");
	myPlayer.addPoint();
	myPlayer.addPoint();

	myPlayer.addToHand("test");
	myPlayer.addToHand("yest");
	myPlayer.addToHand("quest");

	std::cout << myPlayer.getPlayerName() << " " << myPlayer.getPlayerPoints() << std::endl;

	myPlayer.printWinningCards();

	std::vector<std::string> myNewVector = myPlayer.getPlayerCards();

	std::cout << myNewVector[0] << std::endl;
	return 0;
}
