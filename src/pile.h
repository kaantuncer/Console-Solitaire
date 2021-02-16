#include "card.h"
#pragma once


//This class is for storing each pile.


class Pile {
private:
    int closedCount;
public:
    int index;
    Card pile[20];
    Pile();
    int setCard(Card card);
    Card* getTopCard();
    void setClosedCount(int count);
    int open();
    int addCard(Card card[16]);
    int removeCards(int count);
    int getClosedCount();


};


