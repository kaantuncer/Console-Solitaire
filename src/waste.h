
#include "card.h"
#pragma once

//This class is for storing and making changes on waste pile


class Waste {
    Card waste[3];
    Card* deck;
    Card* placeholderDeck;


public:
    Waste(Card* deck,Card* placeholderDeck);
    void drawCards();
    std::string getWasteString();
    Card* getWaste();
    int removeFromWaste(int index);




};

