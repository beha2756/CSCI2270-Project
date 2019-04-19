#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "cardDeck.hpp"

// default constructor
CardDeck::CardDeck(){
    // nothing to do
}
// destructor
CardDeck::~CardDeck(){
    // nothing to do
}
/*
function: dealCard
purpose: returns the card on top of the deck, removes card from the deck
parameters: none
return: text from card on top of deck
*/
std::string CardDeck::dealCard(){
    std::string card;
    if(!deck.empty()){
        card = *(deck.begin());
        deck.pop_front();
    }else{
        card = "";
        std::cout << "you messed up! (trying to deal empty deck)" << std::endl;
    }
    return card;
}

/*
function: getDeckSize
purpose: gets the cards in the deck
parameters: none
return: size of deck
*/
int CardDeck::getDeckSize(){
    return deck.size();
}

/*
function: addToDeck
purpose: adds a card to the bottom of the deck
parameters: cardData - text for card to be added
return: none
*/
void CardDeck::addToDeck(std::string cardData){
    deck.push_back(cardData);
}

/*
function: shuffleDeck
purpose: shuffles the deck using std::shuffle
parameters: none
return: none
*/
void CardDeck::shuffleDeck(){
    //add to a vector for shuffle functionality
    std::vector<std::string> shuffleVec(deck.begin(),deck.end());
    //seeding the random engine
    unsigned int seed = rand();
    //shuffle the vector
    shuffle(shuffleVec.begin(), shuffleVec.end(), std::default_random_engine(seed));
    //repopulate the deck
	deck.assign(shuffleVec.begin(),shuffleVec.end());
}
