
#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "player.hpp"
#include "cardDeck.hpp"

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

  /*
  Purpose: Returns the number of players
  Parameters: None
  Return: Number of players
  */
  int getNumPlayers();

  /*
  Purpose: Returns the number of points to win
  Parameters: None
  Return: Number of points to win
  */
  int getNumPointsToWin();

  /*
  Purpose: Simulates one turn of the game
  Parameters: None
  Return: None
  */
  void playTurn();

  /*
  Purpose: increments the turn counter
  Parameters: None
  Return: None
  */
  void incrementTurnNumber();

  /*
  Purpose: Returns the turn number
  Parameters: None
  Return: Turn number
  */
  int getTurnNumber();

private:
  int pointsToWin;

  int numPlayers;

  std::vector<Player> Players;

  CardDeck blackCards;

  CardDeck whiteCards;

  int turnNumber;
};

#endif
