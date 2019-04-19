#ifndef GAME
#define GAME

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Game
{

public:
  /*
  Purpose: Initializes the number of players in a game to numPlayers
  Parameters: The number of players in the game
  Return: None
  */
  Game(int numPlayers, int maxPoints);

  /*
  Purpose: Reads in a file and store the strings in the white card deck
  Parameters: The name of the file to be read
  Return: None
  */
  void getWhiteDeck(std::string fileName);

  /*
  Purpose: Reads in a file and store the strings in the black card deck
  Parameters: The name of the file to be read
  Return: None
  */
  void getBlackDeck(std::string fileName);

  /*
  Purpose: Deals white cards to each player except for the card czar
  Parameters: The number of cards to be dealt
  Return: None
  */
  void dealHands(int numCards, int cardCzar);

  //gets names of users and adds them to the player class
  void addPlayers();

  /*
  Purpose: Checks to see if the game is over.
  Parameters: None
  Return: None
  */
  bool isGameOver();

  int getNumPlayers();

  int getNumPointsToWin();

  void playTurn();

  void incrementTurnNumber();

  void getTurnNumber();

private:
  int pointsToWin;

  int numPlayers;

  std::vector<Player> Players;

  CardDeck blackCards;

  CardDeck whiteCards

  int turnNumber
};
