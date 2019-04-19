#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

#include "game.hpp"

void disp(std::string filename)
{
	std::ifstream myStream(filename);
	std::string line;
	while(getline(myStream,line))
	{
		std::cout << line << std::endl;
	}
}
void printLine(char c, int n, bool endline)
{
	for(int i=0; i<n;i++)
	{
		std::cout << c;
	}
	if(endline)
	{
		std::cout << std::endl;
	}
}

void playGame(int numPlayers,int maxPoints)
{

	Game myGame(numPlayers,maxPoints);
	std::cout << "Test" << std::endl;
	while(true)
	{
		myGame.playTurn();
	}
}

void mainMenu()
{
	int numPlayers;
	int maxPoints = 5;

	disp("logo.txt");
	printLine('=',211,1);
	std::cout << "          ====[ MAIN MENU ] ====" << std::endl <<std::endl;
	std::cout << "          [ 1 ] New Game" << std::endl;
	std::cout << "          [ 2 ] --------" << std::endl;
	std::cout << "          [ 3 ] Exit" << std::endl;
	std::cout << std::endl;
	std::cout << "          Enter choice: ";

	int choice;

	//Check for correct input
	while(std::cin >> choice)
	{
		if(std::cin && choice >= 1 && choice <= 3)
			break;
		else
			std::cout << "          Invalid input. Please enter a number between 1 and 3." << std::endl;
			std::cout << "          Enter choice: ";
	}

	switch (choice)
	{
		case 1: // new game
		{
			std::cout << std::endl << "          Enter number of players ( Minimum: 3 ): ";
			while(std::cin >> numPlayers)
			{
				if(!std::cin)
				{
					std::cout << "          Error: Input must be integer"  << std::endl;
					std::cout << std::endl << "          Enter number of players ( Minimum: 3): ";
				}
				else if(numPlayers < 3)
				{
					std::cout << "          Error: Game must have at least 3 players" << std::endl;
					std::cout << std::endl << "          Enter number of players ( Minimum: 3): ";
				}
				else
				{
					break;
				}
			}
			std::cout << "          Enter number of points to win: ";
			while(std::cin >> numPlayers)
			{
				if(!std::cin)
				{
					std::cout << "          Error: Input must be integer"  << std::endl;
					std::cout << "          Enter number of points to win: ";
				}
				else if(numPlayers < 1)
				{
					std::cout << "          Error: Number of points to win must be at least 1" << std::endl;
					std::cout << "          Enter number of points to win: ";
				}
				else
				{
					break;
				}
			}
			playGame(numPlayers,maxPoints);
			break;
		}
		case 2:
		{
			break;
		}

		case 3:
		{
			std::cout << std::endl << "          Exited Program" << std::endl;
			break;
		}
	}
}


int main()
{
    srand(time(0));
	mainMenu();


	return 0;
}
