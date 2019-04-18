#ifndef GAME
#define GAME

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Game
{

public:
  Game(int numPlayers);
  //reads in a file and gets all the white card strings
  void getWhiteDeck(std::string fileName);
  //reads in a file and gets all the black card strings
  void getBlackDeck(std::string fileName);
  //deals numCards to ever player
  void dealHands(int numCards);
  //
  //void startGame(int numPlayers);

  void setMaxPoints(int numPoints);
  //gets names of users and adds them to the player class
  void addPlayers();

  //int getNumPlayers(int numPlayers);

  //checks to see if the game is over
  bool isGameOver();

  int getNumPlayers();

  int getNumPointsToWin();

private:
  int pointsToWin;

  int numPlayers;

  std::vector<Player> Players;

  CardDeck blackCards;

  CardDeck whiteCards
};
