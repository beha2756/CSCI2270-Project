#include <iostream>
#include <string>
#include "cardTree.hpp"

void addNewCard(CardTree& ct){
    std::cout << "Please enter the text for your new card" << std::endl;
    std::string newCardText;

    getline(std::cin, newCardText);
    std::string input = "0";
    while(input != "1"){
        std::cout << "Is this correct?" << std::endl;
        std::cout << newCardText << std::endl << std::endl;
        std::cout << "[1] for yes, [2] if you would like to enter different text" << std::endl;
        getline(std::cin, input);
        if(input != "1"){
            std::cout << "Enter the new text" << std::endl;
            getline(std::cin, newCardText);
        }
    }
    std::cout << std::endl;
    std::cout << "Text for new card: " << newCardText << std::endl;

    std::string newCardKeyword;
    std::cout << "Now enter a keyword so that you card can be found easily" << std::endl;
    getline(std::cin, newCardKeyword);
    input = "0";
    while(input != "1"){
        std::cout << std::endl;
        std::cout << "Is this correct?" << std::endl;
        std::cout << newCardKeyword << std::endl << std::endl;
        std::cout << "[1] for yes, [2] if you would like to enter different keyword" << std::endl;
        getline(std::cin, input);

        if(input != "1"){
            std::cout << "Enter a different keyword" << std::endl;
            getline(std::cin, newCardKeyword);
        }
    }
    std::cout << std::endl;

    while(ct.searchDeck(newCardKeyword) != nullptr){
        std::cout << "This keyword is already in your deck. Please enter a different one" << std::endl;
        getline(std::cin, newCardKeyword);
        std::cout << std::endl;
    }

    ct.addCard(newCardText, newCardKeyword);
    std::cout << "Successfully added to your deck!" << std::endl;
}

void editCard(CardTree& ct){
    std::cout << "Please enter the keyword of the card you would like to edit" << std::endl;
    std::string keyWord;
    getline(std::cin, keyWord);
    cardNode *card = ct.searchDeck(keyWord);
    if(card != nullptr){
        std::cout << std::endl;
        std::cout << "Current text: " << card->text << std::endl;
        std::cout << std::endl;
        std::cout << "Please enter the new text for this card" << std::endl;
        std::string newText;
        getline(std::cin, newText);
        std::string input = "0";
        while(input != "1"){
            std::cout << "Is this correct?\n --->" << newText << std::endl;
            std::cout << "[1] Yes   [2] No" << std::endl;
            getline(std::cin, input);
            if(input == "2"){
                std::cout << "Enter the text you would like on the card" << std::endl;
                getline(std::cin, newText);
            }
        }
        card->text = newText;
        std::cout << std::endl;
        std::cout << "Would you like to edit the keyword?" << std::endl;
        input = "0";
        std::cout << "[1] Yes   [2] No" << std::endl;
        getline(std::cin, input);
        std::string newKeyword = card->keyword;
        if(input != "2"){
            std::cout << std::endl;
            std::cout << "Please enter the new keyword" << std::endl;
            getline(std::cin, newKeyword);
            input = "2";
        }else{
            input = "1";
        }
        while(input != "1"){

            std::cout << std::endl;
            std::cout << "Is this correct?" << std::endl;
            std::cout << newKeyword << std::endl << std::endl;
            std::cout << "[1] for yes, [2] if you would like to enter different keyword" << std::endl;
            getline(std::cin, input);

            if(input != "1"){
                std::cout << "Enter a different keyword" << std::endl;
                getline(std::cin, newKeyword);
            }else{
                card->keyword = newKeyword;
            }
        }
    }else{
        std::cout << "That card could not be found. Try again with a different keyword" << std::endl;
        std::cout << "You can print all of the cards to see their keywords" << std::endl;
    }
}

int main(){
    CardTree tree;
    tree.addCard("Text1","K1");
    tree.addCard("Text2","K2");
    tree.addCard("Text3","K3");

    editCard(tree);
    tree.printAllCards();
    return 0;
}
