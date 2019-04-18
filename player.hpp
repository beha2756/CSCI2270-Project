#include <string>
#include <queue>
#include <list>

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


class player
{
    public:

		//constructor
		Player(std::string name);

		~Player();

		void setName();

		//print vector of all winning card pairs
		printWinningCards();

		//incriment player points by 1
		void addPoint();

		//add winning pair to array
		void addWinningPair(std::string blackCard,std::string whiteCard);

		//return player name
		std::string getPlayerName();

		//return player points
		std::string getPlayerPoints();

		//add card string to player's hand
		void addToHand(std::string card);

		//remove card string from player's hand
		void removeFromHand(int cardNum)
		{

		}


    private:

		std::string name;
		int points;
		std::list <std::string> cards;
		std::queue <winningPair> winningPairs;
};
