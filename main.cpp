#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>

#include "game.hpp"
#include "cardTree.hpp"

void mainMenu();
void chooseDeckToModify();
void modifyDeck(bool whiteCard);

/*
Purpose: Runs prompt for user to add new card to a tree
Parameters: Tree to add card to
Return: None
*/
void addNewCard(CardTree& ct)
{
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

/*
Purpose: Runs prompt for user to edit a card
Parameters: Tree in which to edit card
Return: None
*/
void editCard(CardTree& ct)
{
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

/*
Purpose: Prints an ASCII image from text file to console
Parameters: Filename of file to be printed
Return: None
*/
void disp(std::string filename)
{
	std::ifstream myStream(filename);
	std::string line;
	while(getline(myStream,line))
	{
		std::cout << line << std::endl;
	}
}

/*
Purpose: Prints a line of a given char to the console
Parameters: Char to print, number of times to print it, and whether to include an endline
Return: None
*/
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

/*
Purpose: Main game function, called when a game is started
Parameters: Number of players and number of points a player must have to win
Return: None
*/
void playGame(int numPlayers,int maxPoints)
{

	Game myGame(numPlayers,maxPoints);
	myGame.addPlayers();
	myGame.dealHands(7,-1);

	//loops while game is running
	bool gameIsRunning = true;
	while(gameIsRunning)
	{
		//plays a turn
		gameIsRunning = myGame.playTurn();
		//breaks if game is over
		if(myGame.isGameOver()) break;
	}
	//after game ends

	if(gameIsRunning)
	{
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
	else
	{
		mainMenu();
	}



}

/*
Purpose: Allows user to choose which deck they want to modify
Parameters: None
Return: None
*/
void chooseDeckToModify()
{
	std::string temp;
	int choice;

	std::cout << "          ";
	printLine('_',35,true);
	std::cout << "          [1] Modify White Deck" << std::endl;
	std::cout << "          [2] Modify Black Cards" << std::endl;
	std::cout << "          [3] Main Menu" << std::endl;
	std::cout << std::endl;
	std::cout << "          Enter choice: ";

	while(getline(std::cin,temp))
	{
		if(isdigit(temp[0]))
		{
			choice = stoi(temp);

			if(choice >= 1 && choice <= 3) break;
		}

		std::cout << "          Invalid input. Please enter a number between 1 and 3." << std::endl;
		std::cout << "          Enter choice: ";
	}
	switch(choice)
	{
		case 1:
		{
			modifyDeck(true);
			break;
		}
		case 2:
		{
			modifyDeck(false);
			break;
		}
		case 3:
		{
			mainMenu();
			break;
		}
	}
}

/*
Purpose: Allows user to modify a deck, adding/modifying cards
Parameters: Bool for whether deck is white card
Return: None
*/
void modifyDeck(bool whiteCard)
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
	while(choice != 4 || choice != 5)
	{
		std::cout <<std::endl;
		std::cout << "          ";
		printLine('_',35,true);
		std::cout << "          [1] Print "<< (whiteCard ? "White" : "Black") <<" Cards" << std::endl;
		std::cout << "          [2] Add New "<< (whiteCard ? "White" : "Black") <<" Card" << std::endl;
		std::cout << "          [3] Edit Existing "<< (whiteCard ? "White" : "Black") <<" Card" << std::endl;
		std::cout << "          [4] Discard Changes & Go Back" << std::endl;
		std::cout << "          [5] Save Changes & Go Back" << std::endl;
		std::cout << std::endl;
		std::cout << "          Enter choice: ";

		while(getline(std::cin,temp))
		{
			if(isdigit(temp[0]))
				choice = stoi(temp);

			if(choice >= 1 && choice <= 5)
				break;
			else
				std::cout << "          Invalid input. Please enter a number between 1 and 5." << std::endl;
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
				chooseDeckToModify();
				break;
			}
			case 5:
			{
				myCardTree.writeTreeToFile(filename);
				chooseDeckToModify();
				break;
			}
		}
	}
	mainMenu();
}

/*
Purpose: Main menu called from main function, allows user to choose what they want to do
Parameters: None
Return: None
*/
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
		if(isdigit(temp[0]))
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
			std::cout << "          ";
			printLine('_',35,true);
			std::cout << std::endl << "          Enter number of players (3-8): ";
			while(getline(std::cin,temp))
			{
				if(isdigit(temp[0]))
				{
					numPlayers = stoi(temp);

					if(numPlayers >= 3 && numPlayers <= 8) break;
				}
				std::cout << "          Invalid Input" << std::endl;
				std::cout << "          Enter number of players (3-8): ";
			}
			std::cout << std::endl << "          Enter number of points to win (at least 1): ";
			while(getline(std::cin,temp))
			{
				if(isdigit(temp[0]))
				{
					maxPoints = stoi(temp);

					if(maxPoints > 0) break;
				}
				std::cout << "          Invalid Input" << std::endl;
				std::cout << "          Enter number of points to win (at least 1): ";
			}
			std::cout << std::endl;
			playGame(numPlayers,maxPoints);
			break;
		}
		case 2: // deck building
		{
			chooseDeckToModify();
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
