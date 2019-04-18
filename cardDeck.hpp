#include <string>
#include <list>

class CardDeck
{
public:
    // default constructor
    CardDeck();
    // destructor
    ~CardDeck();
    /*
    function: dealCard
    purpose: returns the card on top of the deck, removes card from the deck
    parameters: none
    return: text from card on top of deck
    */
    std::string dealCard();

    /*
    function: getDeckSize
    purpose: gets the cards in the deck
    parameters: none
    return: size of deck
    */
    int getDeckSize();

    /*
    function: addToDeck
    purpose: adds a card to the bottom of the deck
    parameters: cardData - text for card to be added
    return: none
    */
    void addToDeck(std::string cardData);

    /*
    function: shuffleDeck
    purpose: shuffles the deck using
    */
    void shuffleDeck();

private:
    std::list<std::string> deck;
};
