#pragma once

//This class is for storing and making changes on foundation piles.

class Foundation{


    Card foundation[4][13];

    int index1;
    int index2;
    int index3;
    int index4;
    char type1;
    char type2;
    char type3;
    char type4;
public:
    Card removeCard(int index);
    Foundation();
    int addCard(Card card);
    std::string getTopCards();
    bool isComplete();

};
