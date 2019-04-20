#include <iostream>
#include <string>

struct cardNode {
    std::string text;
    std::string keyword;
    cardNode *left;
    cardNode *right;
    cardNode(std::string t, std::string k){
        text = t;
        keyword = k;
        left = nullptr;
        right = nullptr;
    }
};


class CardTree {
public:
    //constructor
    CardTree();
    //destructor
    ~CardTree();
    // prints all cards in alphabetical order by keyword
    void printAllCards();
    // returns a pointer to a node containing the card with the keyword
    cardNode* searchDeck(std::string keyword);
    // add a new card to the deck
    void addCard(std::string text, std::string keyword);
    // writes the cards to a file again (by keyword) in case there are new cards added
    void writeTreeToFile(std::string filename);
private:
    cardNode *root;
};
