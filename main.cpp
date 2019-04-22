#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

#include "game.hpp"
#include "cardTree.hpp"

void addNewCard(CardTree& ct){
    std::cout << "Please enter the text for your new card" << std::endl;
    std::string newCardText;

    getline(std::cin, newCardText);
    std::string input = "0";
    while(input != "1"){
        std::cout << "Is this correct?" << std::endl;
        std::cout << newCardText << std::endl << std::endl;
        std::cout << "[1] for yes, [2] if you would like to enter different text" << std::endl;
        getline(std::cin, input);
        if(input != "1"){
            std::cout << "Enter the new text" << std::endl;
            getline(std::cin, newCardText);
        }
    }
    std::cout << std::endl;
    std::cout << "Text for new card: " << newCardText << std::endl;

    std::string newCardKeyword;
    std::cout << "Now enter a keyword so that you card can be found easily" << std::endl;
    getline(std::cin, newCardKeyword);
    input = "0";
    while(input != "1"){
        std::cout << std::endl;
        std::cout << "Is this correct?" << std::endl;
        std::cout << newCardKeyword << std::endl << std::endl;
        std::cout << "[1] for yes, [2] if you would like to enter different keyword" << std::endl;
        getline(std::cin, input);

        if(input != "1"){
            std::cout << "Enter a different keyword" << std::endl;
            getline(std::cin, newCardKeyword);
        }
    }
    std::cout << std::endl;

    while(ct.searchDeck(newCardKeyword) != nullptr){
        std::cout << "This keyword is already in your deck. Please enter a different one" << std::endl;
        getline(std::cin, newCardKeyword);
        std::cout << std::endl;
    }

    ct.addCard(newCardText, newCardKeyword);
    std::cout << "Successfully added to your deck!" << std::endl;
}

void editCard(CardTree& ct){
    std::cout << "Please enter the keyword of the card you would like to edit" << std::endl;
    std::string keyWord;
    getline(std::cin, keyWord);
    cardNode *card = ct.searchDeck(keyWord);
    if(card != nullptr){
        std::cout << std::endl;
        std::cout << "Current text: " << card->text << std::endl;
        std::cout << std::endl;
        std::cout << "Please enter the new text for this card" << std::endl;
        std::string newText;
        getline(std::cin, newText);
        std::string input = "0";
        while(input != "1"){
            std::cout << "Is this correct?\n --->" << newText << std::endl;
            std::cout << "[1] Yes   [2] No" << std::endl;
            getline(std::cin, input);
            if(input == "2"){
                std::cout << "Enter the text you would like on the card" << std::endl;
                getline(std::cin, newText);
            }
        }
        card->text = newText;
        std::cout << std::endl;
        std::cout << "Would you like to edit the keyword?" << std::endl;
        input = "0";
        std::cout << "[1] Yes   [2] No" << std::endl;
        getline(std::cin, input);
        std::string newKeyword = card->keyword;
        if(input != "2"){
            std::cout << std::endl;
            std::cout << "Please enter the new keyword" << std::endl;
            getline(std::cin, newKeyword);
            input = "2";
        }else{
            input = "1";
        }
        while(input != "1"){

            std::cout << std::endl;
            std::cout << "Is this correct?" << std::endl;
            std::cout << newKeyword << std::endl << std::endl;
            std::cout << "[1] for yes, [2] if you would like to enter different keyword" << std::endl;
            getline(std::cin, input);

            if(input != "1"){
                std::cout << "Enter a different keyword" << std::endl;
                getline(std::cin, newKeyword);
            }else{
                card->keyword = newKeyword;
            }
        }
    }else{
        std::cout << "That card could not be found. Try again with a different keyword" << std::endl;
        std::cout << "You can print all of the cards to see their keywords" << std::endl;
    }
}

void mainMenu();
void deckBuilding1();
void deckBuilding2(bool whiteCard);

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

	//add the players
	myGame.addPlayers();


	//deal the first hand
	myGame.dealHands(7,-1);
	//loops while game is running

	while(true)
	{
		//plays a turn
		myGame.playTurn();
		//breaks if game is over
		if(myGame.isGameOver()) break;
	}
	//after game ends
	myGame.printWinningCards();

	std::string playAgain;
	std::cout << "          Play again? (y/n): ";
	getline(std::cin,playAgain);

	if(playAgain[0] == 'y' || playAgain[0] == 'Y')
	{
		mainMenu();
	}
	else
	{
		std::cout << "Exiting program" << std::endl;
	}

}

void deckBuilding1()
{
	std::string temp;
	int choice;
	std::cout << "          === [ MODIFY  DECK ] ===" << std::endl <<std::endl;
	std::cout << "          [1] White Cards" << std::endl;
	std::cout << "          [2] Black Cards" << std::endl;
	std::cout << "          [3] Main Menu" << std::endl;
	std::cout << std::endl;
	std::cout << "          Enter choice: ";

	while(getline(std::cin,temp))
	{
		choice = stoi(temp);
		if(choice >= 1 && choice <= 3)
			break;
		else
			std::cout << "          Invalid input. Please enter a number between 1 and 3." << std::endl;
			std::cout << "          Enter choice: ";
	}
	switch(choice)
	{
		case 1:
		{
			deckBuilding2(true);
			break;
		}
		case 2:
		{
			deckBuilding2(false);
			break;
		}
		case 3:
		{
			mainMenu();
			break;
		}
	}
}
void deckBuilding2(bool whiteCard)
{
	CardTree myCardTree;
	std::string filename = (whiteCard ? "whiteCards.txt" : "blackCards.txt");
	std::ifstream cardStream(filename);

	std::string text,key;
	while(getline(cardStream,text,'|'))
	{
		getline(cardStream,key);
		myCardTree.addCard(text,key);
	}
	//read cards in to trees

	//print cards
	std::string temp;
	int choice = 0;
	while(choice != 4)
	{
		std::cout << std::endl <<std::endl;
		std::cout << "          [1] Print "<< (whiteCard ? "White" : "Black") <<" Cards" << std::endl;
		std::cout << "          [2] Add New "<< (whiteCard ? "White" : "Black") <<" Card" << std::endl;
		std::cout << "          [3] Edit Existing "<< (whiteCard ? "White" : "Black") <<" Card" << std::endl;
		std::cout << "          [4] Go back without saving" << std::endl;
		std::cout << "          [5] Save and go back" << std::endl;
		std::cout << std::endl;
		std::cout << "          Enter choice: ";

		while(getline(std::cin,temp))
		{
			choice = stoi(temp);
			if(choice >= 1 && choice <= 4)
				break;
			else
				std::cout << "          Invalid input. Please enter a number between 1 and 4." << std::endl;
				std::cout << "          Enter choice: ";
		}
		std::cout << std::endl;
		switch(choice)
		{
			case 1:
			{
				myCardTree.printAllCards();
				break;
			}
			case 2:
			{
				addNewCard(myCardTree);
				break;
			}
			case 3:
			{
				editCard(myCardTree);
				break;
			}
			case 4:
			{
				deckBuilding1();
				break;
			}
			case 5:
			{
				myCardTree.writeTreeToFile(filename);
				deckBuilding1();
				break;
			}
		}
	}
	mainMenu();
}

void mainMenu()
{
	std::string temp;
	int numPlayers;
	int maxPoints = 5;
	int choice;

	disp("logo.txt");
	std::cout << std::endl;
	std::cout << "          ==== [ MAIN  MENU ] ====" << std::endl <<std::endl;
	std::cout << "          [1] New Game" << std::endl;
	std::cout << "          [2] Add or Modify Cards" << std::endl;
	std::cout << "          [3] Exit" << std::endl;
	std::cout << std::endl;
	std::cout << "          Enter choice: ";




	//Check for correct input
	while(getline(std::cin,temp))
	{
		choice = stoi(temp);
		if(choice >= 1 && choice <= 3)
			break;
		else
			std::cout << "          Invalid input. Please enter a number between 1 and 3." << std::endl;
			std::cout << "          Enter choice: ";
	}
	std::cout << std::endl;




	switch (choice)
	{
		case 1: // new game
		{
			std::cout << "          ====[ GAME SETUP ] ====" << std::endl <<std::endl;
			std::cout << std::endl << "          Enter number of players ( Minimum: 3 ): ";
			while(getline(std::cin,temp))
			{
				numPlayers = stoi(temp);
				if(!std::cin)
				{
					std::cout << "          Error: Input must be integer"  << std::endl;
					std::cout << std::endl << "          Enter number of players ( Minimum: 3): ";
				}
				else if(numPlayers < 3 || numPlayers > 8)
				{
					std::cout << "          Error: Game must have 3-8 players" << std::endl;
					std::cout << std::endl << "          Enter number of players ( Minimum: 3): ";
				}
				else
				{
					break;
				}
			}
			std::cout << "          Enter number of points to win: ";
			while(getline(std::cin,temp))
			{
				maxPoints = stoi(temp);
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
			std::cout << std::endl;
			playGame(numPlayers,maxPoints);
			break;
		}
		case 2: // deck building
		{
			deckBuilding1();
			break;
		}

		case 3: // exit
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
