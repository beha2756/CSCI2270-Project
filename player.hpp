#include <string>
#include <queue>
#include <vector>
#include <iostream>

// a struct to store customers group information
struct winningPair
{
  std::string whiteCard;
	std::string blackCard;

	winningPair(std::string bc, std::string wc)
	{
		blackCard = bc;
		whiteCard = wc;
	}
};


class Player
{
    public:

		//constructor
		Player();

		~Player();

		void setName(std::string n);

		//print vector of all winning card pairs
		void printWinningCards();

		//incriment player points by 1
		void addPoint();

		//add winning pair to array
		void addWinningPair(std::string blackCard,std::string whiteCard);

		//return player name
		std::string getPlayerName();

		//return player points
		int getPlayerPoints();

		//add card string to player's hand
		void addToHand(std::string card);

		//remove card string from player's hand
		std::string playCard(int cardNum);

		std::vector<std::string> getPlayerCards();

    private:

		std::string name;
		int points;
		std::vector <std::string> cards;
		std::vector <winningPair> winningPairs;
};
