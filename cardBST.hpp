#include <iostream>
#include <string>

struct cardNode {
    std::string text;
    cardNode *left;
    cardNode *right;
    cardNode(std::string t){
        text = t;
        left = nullptr;
        right = nullptr;
    }
};


class cardTree {
public:
    //constructor
    cardTree();
    //destructor
    ~cardTree();
    // prints all cards in alphabetical order
    void printAllCards();
    // returns a pointer to a node containing the card with the keyword
    cardNode* searchDeck(std::string keyword);
    // add a new card to the deck
    void addCard(std::string text);
    // writes the cards to a file again in case there are new cards added
    void writeTreeToFile(std::string filename);
private:
    cardNode *root;
};
