#include "cardTree.hpp"

#include <fstream>
#include <iostream>

//constructor
CardTree::CardTree(){
    root = nullptr;
}

void deleteTree(cardNode *node){
    if(node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

//destructor
CardTree::~CardTree(){
    deleteTree(root);
}

void printCardHelper(cardNode* node){
    if(node == nullptr) return;

    printCardHelper(node->left);
    std::cout << "Keyword: " << node->keyword << std::endl;
    std::cout << "     " << node->text << std::endl;
    printCardHelper(node->right);
}

// prints all cards in alphabetical order by keyword
void CardTree::printAllCards(){
    printCardHelper(root);
}



cardNode* searchHelper(cardNode *node, std::string keyword){
    if(node == nullptr || node->keyword == keyword) return node;

    if(keyword < node->keyword) return searchHelper(node->left, keyword);

    return searchHelper(node->right, keyword);
}

// returns a pointer to a node containing the card with the keyword
cardNode* CardTree::searchDeck(std::string keyword){
    return searchHelper(root, keyword);
}

cardNode* createNode(std::string text, std::string keyword){
    cardNode *nn = new cardNode(text, keyword);
    return nn;
}
cardNode* CardTree::addCardHelper(std::string text, std::string keyword, cardNode *node){
    if(root == nullptr){
        root = createNode(text, keyword);
        return node;
    }

    if(keyword < node->keyword){
        if(node->left == nullptr){
            node->left = createNode(text, keyword);
            return node;
        }else{
            return addCardHelper(text, keyword, node->left);
        }
    }else{
        if(node->right == nullptr){
            node->right = createNode(text, keyword);
            return node;
        }else{
            return addCardHelper(text, keyword, node->right);
        }
    }
}

// add a new card to the deck
void CardTree::addCard(std::string text, std::string keyword){
    addCardHelper(text, keyword, root);
}

void writingHelper(std::ofstream& os, cardNode *node){
    if(node == nullptr) return;

    writingHelper(os, node->left);

    writingHelper(os, node->right);

    os << node->text << "|" << node->keyword << std::endl;
}

// writes the cards to a file for future use
void CardTree::writeTreeToFile(std::string filename){
    std::ofstream outFile;
    outFile.open(filename);

    writingHelper(outFile, root);

    outFile.close();

}
