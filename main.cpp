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

	std::cout << myPlayer.getPlayerName() << " " << myPlayer.getPlayerPoints() << std::endl;

	return 0;
}
