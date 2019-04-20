#include "cardBST.hpp"

#include <fstream>
#include <iostream>

//constructor
CardTree::CardTree(){
    root = nullptr;
}

//destructor
~CardTree(){

}

void printCardHelper(cardNode* root){
    if(root == nullptr) return;

    printCardHelper(root->left);
    std::cout << root->text << std::endl;
    printCardHelper(root->right);
}

// prints all cards in alphabetical order by keyword
void CardTree::printAllCards(){
    printCardHelper(root);
}



cardNode* searchHelper(cardNode *node, std::string keyword){
    
}

// returns a pointer to a node containing the card with the keyword
cardNode* searchDeck(std::string keyword){
    return searchHelper(root, keyword);
}

// add a new card to the deck
void addCard(std::string text, std::string keyword);

// writes the cards to a file in alphabetical order (by keyword) again in case there are new cards added
void writeTreeToFile(std::string filename);
